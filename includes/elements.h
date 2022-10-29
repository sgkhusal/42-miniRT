/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:59:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:36:47 by sguilher         ###   ########.fr       */
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

typedef struct s_camera
{
	t_point		origin;
	t_vector	orientation;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_point		position;
	t_vector	intensity; // normalized color
	t_color		color;
	double		brightness;
}				t_light;

typedef struct s_ambient
{
	t_vector	intensity; // normalized color
	t_color		color;
	double		ratio;
}				t_ambient;

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
	t_vector	normalized_color;
	double		diffuse;
	double		ambient;
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
	t_matrix	transform;
	t_matrix	inverse;
	t_matrix	transpose_inverse;
	t_material	material;
}				t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vector	orientation;
	t_material	material;
}				t_plane;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	orientation;
	double		radius;
	double		height;
	t_material	material;
}				t_cylinder;

typedef struct s_object
{
	void			*obj;
	t_point			xyz;
	t_color			color;
	enum e_objects	type;
	struct s_object	*next;
}				t_object;

// material
t_material	set_material(void);

// light
t_vector	reflect(t_vector incident, t_vector normal);
t_light		set_point_light(t_point position, t_vector intensity);
t_vector	lighting(t_material material, t_light light, t_point point,
				t_vector normal, t_vector eye);

// objects
t_object	*create_object(enum e_objects type, void *shape);
void		append_object(t_object **head, t_object *obj);
void		free_objects(t_object **head);

// sphere
t_sphere	*create_sphere(void);
void		free_sphere(t_sphere *sphere);
void		set_transform(t_sphere *sphere, t_matrix transform);
t_vector	sphere_normal_at(t_sphere *s, t_point p);

#endif
