/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 12:51:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# include "utils.h"
# include "elements.h"

/**
 * @brief struc containing ray properties
 * @param origin origin of the ray
 * @param direction direction of the ray
 */
typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

/**
 * @brief struct containing intersection properties related to a ray
 * @param t1 the distance from the ray origin to the first intersection
 * @param t2 the distance from the ray origin to the second intersection
 * @param count the number of intersections. If there's only one intersection,
 * count = 2 and t2 = t1 and if there are no intersections, count = 0.
 */
typedef struct s_xs
{
	double	t1;
	double	t2;
	int		count;
}				t_xs;

/**
 * @brief struct containing a intersection node values
 * @param t the distance from the ray origin to the intersection
 * @param object the object that was intersected
 * @param next the next node in the list
 */
typedef struct s_intersection
{
	double					t;
	t_object				*object;
	struct s_intersection	*next;
}				t_intersection;

/**
 * @brief struct containing a list of intersections
 * @param head the first node in the list
 * @param last the last node in the list
 * @param total the total number of nodes in the list
 */
typedef struct intersection_list
{
	t_intersection			*head;
	t_intersection			*last;
	int						total;
}				t_intersection_list;

/**
 * @brief struct containing the precomputed information related to a
 * intersection
 * @param xs information related to the intersection (number of intersections
 * and the distances from the ray origin to the intersections)
 * @param point the point of the intersection
 * @param over_point the point of the intersection with a small offset in the
 * normal direction. This will bump it above the surface and prevent
 self-shadowing.
 * @param eyev the vector from the intersection point to the eye
 * @param normalv the normal vector at the intersection point
 * @param inside if the ray is inside the object
 */
typedef struct s_comp
{
	t_intersection	*xs;
	t_point			point;
	t_point			over_point;
	t_vector		eyev;
	t_vector		normalv;
	enum e_bool		inside;
}				t_comp;

/**
 * @brief struct containing the lights and objects of the scene along with
 * the ambient light
 * @param ambient the ambient normalized color * ambient ratio
 * @param lights the list of lights in the scene
 * @param objects the list of objects in the scene
 */
typedef struct s_world
{
	t_light		*lights;
	t_object	*objects;
	t_vector	ambient;
}				t_world;

/**
 * @brief main struct containing the scene information, camera, canvas and mlx.
 * @param camera the camera
 * @param world the world (lights and objects)
 * @param canvas the canvas
 * @param mlx the mlx structure
 */
typedef struct s_rt
{
	t_camera	camera;
	t_vector	**canvas;
	t_world		world;
	t_mlx		mlx;
}				t_rt;

/* input functions */
int					handle_input(int argc, char *filename, t_rt	*rt);
int					check_file_extension(char *file);
int					open_file(char *file);
int					read_file(int fd, char **content);
int					handle_content(char **lines, t_rt	*rt);
int					handle_line(char *line, t_rt *rt);
int					handle_ambient_light(char *line, t_vector *amb);
int					handle_camera(char *line, t_camera *cam);
int					handle_light(char *line, t_light **head);
int					handle_sphere(char *line, t_object **objs);
int					handle_plane(char *line, t_object **objs);
int					handle_cylinder(char *line, t_object **objs);
void				set_ambient_light(t_object **objects, t_vector amb);
t_vector			set_up(t_vector orientation);

/* rays functions */
t_ray				set_ray(t_point origin, t_vector direction);
t_point				ray_position(t_ray ray, double distance);
t_ray				transform_ray(t_ray ray, t_matrix m);
t_ray				ray_for_pixel(t_camera cam, double x, double y);

/* intersections functions */
t_xs				sphere_intersection(t_ray ray, t_object *o);
t_xs				cylinder_intersection(t_ray ray, t_object *o);
t_xs				plane_intersection(t_ray ray, t_object *p);
t_intersection		*create_intersection(double t, t_object *object);
void				add_intersection_node(t_intersection *node,
						t_intersection_list *list);
t_intersection		*get_hit_intersection(t_intersection_list list);
void				init_intersection_list(t_intersection_list *list);
void				free_intersection_list(t_intersection_list *list);
t_intersection_list	intersect_world(t_world world, t_ray ray);
void				add_intersections(t_xs xs, t_object *object,
						t_intersection_list *list);
void				intersect_sort(t_intersection **head);

/* color calculation functions */
t_vector			color_at(t_world world, t_ray ray);
t_comp				prepare_computations(t_ray ray, t_intersection *intersect);
t_vector			get_total_color(t_world world, t_comp comps);
t_vector			shade_hit(t_world world, t_comp comps, t_light light);
t_bool				is_shadowed(t_world w, t_point point, t_light light);
t_vector			lighting(t_material material, t_light light, t_comp comp,
						t_bool shadow);

/* render function */
void				render(t_camera camera, t_world w, t_vector **canvas,
						t_mlx *mlx);

/* clean function */
void				clean_minirt(t_rt *rt, t_vector	**canvas);

#endif
