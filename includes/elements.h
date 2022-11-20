/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:59:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/16 221::400:444 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "utils.h"

enum e_objects
{
	SPHERE,
	PLANE,
	CYLINDER
};

/**
 * @param origin is the origin of the camera
 * @param orientation is the direction of the ray
 * @param hsize is the horizontal size of the canvas
 * @param vsize is the vertical size of the canvas
 * @param transform is the transformation matrix of the camera
 * @param fov is the field of view of the camera
 */
typedef struct s_camera
{
	double		fov;
	t_point		origin;
	t_vector	orientation;
	t_matrix	transform;
	t_matrix	inverse;
	int			hsize;
	int			vsize;
	double 		pixel_size;
	double		half_width;
	double		half_height;
}				t_camera;

// intensity is the normalized(color in rgb) * brightness
typedef struct s_light
{
	t_point		position;
	t_vector	intensity;
}				t_light;

/**
 * @param color normalized color with range [0-1]
 * @param diffuse diffuse color with range [0-1]
 * @param ambient ambient color with range [0-1]
 * @param specular specular color with range [0-1]
 * @param shininess shininess value with range [10-200]
 * (at least?)(very small highlight)
 */
typedef struct s_material
{
	t_vector	color;
	t_vector	ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

typedef struct s_shading
{
	t_vector	diffuse;
	t_vector	ambient;
	t_vector	specular;
}				t_shading;

typedef struct s_sphere
{
	t_point		center;
	double		radius;
}				t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vector	orientation;
}				t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	orientation;
	double		radius;
	double		height;
	double		min;
	double		max;
}				t_cylinder;

typedef union u_shape
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_shape;

typedef struct s_object
{
	enum e_objects	type;
	t_shape			shape;
	t_matrix		transform;
	t_matrix		inverse;
	t_matrix		transpose_inverse;
	t_material		material;
	struct s_object	*next;
}				t_object;

// material
t_material	set_material(void);

// light
t_vector	reflect(t_vector incident, t_vector normal);
t_light		set_point_light(t_point position, t_vector intensity);

// objects
t_object	*create_object(enum e_objects type, void *shape);
void		set_transform(t_object *o, t_matrix transform);
void		append_object(t_object **head, t_object *obj);
void		free_objects(t_object **head);

// sphere
t_sphere	*create_sphere(void);
t_vector	sphere_normal_at(t_object *s, t_point p);

// plane
t_plane		*create_plane(void);
t_vector	plane_normal_at(t_object *p, t_point world_point);

// cylinder
t_cylinder	*create_cylinder(void);
t_vector	cylinder_normal_at(t_object *c, t_point p);

// camera
t_camera	set_camera(double fov, int hsize, int vsize);
void		free_camera(t_camera *camera);

#endif
