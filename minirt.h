/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/29 10:34:110 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h> // printf
# include <math.h>
# include <fcntl.h> // open flags

# include "utils.h"
# include "elements.h"

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

/**
 * @param t1 the distance from the ray origin to the first intersection
 * @param t2 the distance from the ray origin to the second intersection
 * @param count the number of intersections. If there's only one intersection,
 * count = 2 and t2 = t1 and if there are no intersections, count = 0.
 */
typedef struct s_xs
{
	double	t1; // talvez saia
	double	t2;
	int		count;
}				t_xs;

/* if hit < 0, the intersection is behind the camera
 * if hit = 0, the intersection is at the camera
 * if hit > 0, the intersection is ahead of the camera
 * the visible intersection is the smaller positive number
 */
typedef struct s_intersection
{
	double					t;
	t_object				*object;
	struct s_intersection	*next;
}				t_intersection;

typedef struct intersection_list
{
	t_intersection			*head;
	t_intersection			*last;
	int						total;
}				t_intersection_list;

typedef struct s_comp
{
	t_intersection *xs;
	t_point			point;
	t_point			over_point;
	t_vector		eyev;
	t_vector		normalv;
	enum e_bool		inside;
}				t_comp;

typedef struct s_world
{
	t_light		light;
	t_object	*objects;
}				t_world;

// ambient is the normalized(ambient color) * ambient ratio
typedef struct s_rt
{
	t_vector	ambient;
	t_camera	camera;
	t_vector	**canvas;
	t_world		world;
	t_mlx		mlx;
}				t_rt;

// input
int					handle_input(int argc, char *filename, t_rt	*rt);
int					check_file_extension(char *file);
int					open_file(char *file);
int					read_file(int fd, char **content);
int					handle_content(char **lines, t_rt	*rt);
int					handle_line(char *line, t_rt *rt);
int					handle_ambient_light(char *line, t_vector *amb);
int					handle_camera(char *line, t_camera *cam);
int					handle_light(char *line, t_light *light);
int					handle_sphere(char *line, t_object **objs);
int					handle_plane(char *line, t_object **objs);
int					handle_cylinder(char *line, t_object **objs);
void				set_ambient_light(t_object **objects, t_vector amb);

// rays
t_ray				set_ray(t_point origin, t_vector direction);
t_point				ray_position(t_ray ray, double distance);
t_ray				transform_ray(t_ray ray, t_matrix m);

// intersections
t_xs				sphere_intersection(t_ray ray, t_object *o);
t_xs				cylinder_intersection(t_ray ray, t_object *o);
t_xs		plane_intersection(t_ray ray, t_object *p);
t_intersection		*create_intersection(double t, t_object *object);
void				add_intersection_node(t_intersection *node,
						t_intersection_list *list);
t_intersection		*get_hit_intersection(t_intersection_list list);
void				init_intersection_list(t_intersection_list *list);
void				free_intersection_list(t_intersection_list *list);
t_intersection_list	intersect_world(t_world world, t_ray ray);
void				add_intersections(t_xs xs, t_object *object,
						t_intersection_list *list);

// color
t_vector			lighting(t_material material, t_light light, t_comp comp,
						t_bool shadow);

//intersect_sort
void				intersect_sort(t_intersection **head);

//computations
t_comp				prepare_computations(t_ray ray, t_intersection *intersect);

//shade hit
t_vector			shade_hit(t_world world, t_comp comps);
t_vector			color_at(t_world world, t_ray ray);

//view transform
t_matrix			view_transform(t_point from, t_vector forward, t_vector up);
void				set_camera_transform(t_camera *cam, t_matrix transform);
t_ray				ray_for_pixel(t_camera cam, double x, double y);

void				render(t_camera camera, t_world w,
	t_vector **canvas, t_mlx *mlx);

//is_shadowed
t_bool				is_shadowed(t_world w, t_point point);

#endif
