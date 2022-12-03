/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:39:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 15:20:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "utils.h"

/**
 * @brief enum for each shape that can be rendered
 */
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
	double		pixel_size;
	double		half_width;
	double		half_height;
}				t_camera;

/**
 * @brief struct which stores the position and intensity of the light
 * @param intensity is the normalized(color in rgb) * brightness
 */
typedef struct s_light
{
	t_point			position;
	t_vector		intensity;
	struct s_light	*next; //
}				t_light;

/**
 * @brief material struct which stores the material properties of the object
 * @param color normalized color with range [0-1]
 * @param diffuse diffuse color with range [0-1]
 * @param ambient ambient color with range [0-1]
 * @param specular specular color with range [0-1]
 * @param shininess shininess value with range [10-200]
 */
typedef struct s_material
{
	t_vector	color;
	t_vector	ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

/**
 * @brief shading struct which stores the shading properties of the object
 * to calculate the shading in the lighting function
 */
typedef struct s_shading
{
	t_vector	diffuse;
	t_vector	ambient;
	t_vector	specular;
}				t_shading;

/**
 * @brief struct which stores the properties of the sphere
 * @param center is the center of the sphere
 * @param radius is the radius of the sphere
 */
typedef struct s_sphere
{
	t_point		center;
	double		radius;
}				t_sphere;

/**
 * @brief struct which stores the properties of the plane
 * @param point is a point on the plane
 * @param orientation is the normal vector of the plane
 */
typedef struct s_plane
{
	t_point		point;
	t_vector	orientation;
}				t_plane;

/**
 * @brief struct which stores the properties of the cylinder
 * @param center is the center of the cylinder
 * @param radius is the radius of the cylinder
 * @param orientation is the normal vector of the cylinder
 * @param height is the height of the cylinder
 * @param min used to handle the bottom cap of the cylinder
 * @param max used to handle the top cap of the cylinder
 */
typedef struct s_cylinder
{
	t_point		center;
	t_vector	orientation;
	double		radius;
	double		height;
	double		min;
	double		max;
}				t_cylinder;

/**
 * @brief union which stores each possible shape's struct
 * carrying its specific properties.
 */
typedef union u_shape
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_shape;

/**
 * @brief struct which stores the properties common to all shapes
 * @param type is the type of the object (sphere, plane, cylinder)
 * @param material is the material of the object
 * @param shape is the shape union carrying the struct of the specific shape
 * @param transform is the transformation matrix of the object
 * @param inverse is the inverse of the transformation matrix of the object
 * @param transpose_inverse is the transpose of the inverse of the transformation
 * @param next is the pointer to the next object in the linked list
 */
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

/* material properties function */
t_material	set_material(void);

/* lighting functions */
t_vector	reflect(t_vector incident, t_vector normal);
t_light		set_point_light(t_point position, t_vector intensity);
t_light		*create_point_light(t_point position, t_vector intensity);
void		append_light(t_light **head, t_light *light);
void		free_lights(t_light **head);

/* object functions */
t_object	*create_object(enum e_objects type, void *shape);
void		set_transform(t_object *o, t_matrix transform);
void		append_object(t_object **head, t_object *obj);
void		free_objects(t_object **head);

/* sphere functions */
t_sphere	*create_sphere(void);
t_vector	sphere_normal_at(t_object *s, t_point p);

/* plane functions */
t_plane		*create_plane(void);
t_vector	plane_normal_at(t_object *p, t_point world_point);

/* cylinder functions */
t_cylinder	*create_cylinder(void);
t_vector	cylinder_normal_at(t_object *c, t_point p);

/* camera functions */
t_camera	set_camera(double fov, int hsize, int vsize);
void		free_camera(t_camera *camera);

#endif
