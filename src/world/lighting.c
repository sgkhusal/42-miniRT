/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:16:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 12:06:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief The reflect() function will calculate the resultof reflecting the
 * incident vector around the normal vector. This is used by the get_specular()
 * function to calculate the specular component of the lighting because it
 * ilustrates the correlation between the light source and the vector that
 * reflects the light in the direction of the viewer (camera).
 *
 * @param incident the vector that represents the incident light
 * @param normal the vector that represents the normal of the surface
 * @return t_vector the reflected vector
 */
t_vector	reflect(t_vector incident, t_vector normal)
{
	double		scalar;
	t_vector	multiply;
	t_vector	reflected;

	scalar = scalar_product(incident, normal);
	multiply = multiply_vector_by_scalar(normal, 2 * scalar);
	reflected = subtract_vectors(incident, multiply);
	return (reflected);
}

/**
 * @brief This function calculates the specular component of the lighting.
 * The specular component is the light reflected from a shiny surface in a
 * perferctly reflected direction. It will be used bythe lighting() function.
 *
 * @param reflect_dot_eye the cosine of the angle between the reflection vector
 * and the eye vector. A negative number means the light reflects away from the
 * eye.

 * @param m the material of the object
 * @param light the light source
 * @param comp the precomputed values
 * @param light_vect the normalized vector that represents the direction of the
 * light source
 * @return t_vector the specular component of the lighting
 */
t_vector	get_specular(t_material m, t_light light, t_comp comp,
							t_vector light_vect)
{
	t_vector	specular;
	t_vector	reflected;
	double		reflected_dot_eye;

	reflected = reflect(negative_vector(light_vect), comp.normalv);
	reflected_dot_eye = scalar_product(reflected, comp.eyev);
	if (reflected_dot_eye < 0 || check_double_values(reflected_dot_eye, 0))
		specular = set_vector(0, 0, 0);
	else
		specular = multiply_vector_by_scalar(light.intensity,
				pow(reflected_dot_eye, m.shininess) * m.specular);
	return (specular);
}

/**
 * @brief This is the function that will calculate the shading so that the
 * objects will appear to be three-dimensional. It will add together the
 * material's ambient, diffuse, and specular components, weighted by the angles
 * between the different vectors.
 *
 * @param light_vect the direction from the point to the light source
 * @param light_dot_normal the cosine of the angle between the light vector and
 * the normal vector. A negative number means the light is on the other side of
 * the surface.

 * @param m the material of the object
 * @param light the light source
 * @param comp the precomputed values of the intersection
 * @param shadow if the object is in shadow or not
 * @return t_vector the final shading of the object
 */
t_vector	lighting(t_material m, t_light light, t_comp comp, t_bool shadow)
{
	t_vector	eff_color;
	t_vector	light_vect;
	t_shading	sh;
	double		light_dot_normal;

	eff_color = multiply_colors(m.color, light.intensity);
	light_vect = normalize_vector(subtract_points(light.position, comp.point));
	light_dot_normal = scalar_product(light_vect, comp.normalv);
	if (light_dot_normal < 0 || shadow == TRUE)
		return (set_vector(0, 0, 0));
	sh.diffuse = multiply_vector_by_scalar(eff_color,
			m.diffuse * light_dot_normal);
	sh.specular = get_specular(m, light, comp, light_vect);
	return (add_vectors(sh.diffuse, sh.specular));
}

/**
 * @brief A ray tracer computes shadows by casting a ray, called a shadow ray,
 * from each point of intersection toward the light source. If something
 * intersects that shadow ray between the point and the light source, then the
 * point is considered to be in shadow. This function will check if the point is
 * in shadow or not and return a boolean value that will be used by the
 * lighting() function to shade the object.
 *
 * @param w the world
 * @param point the point of intersection
 * @param light the light source
 * @return t_bool TRUE if the point is in shadow, FALSE if not
 */
t_bool	is_shadowed(t_world w, t_point point, t_light light)
{
	t_vector			v;
	double				distance;
	t_ray				r;
	t_intersection_list	list;
	t_intersection		*hit;

	v = subtract_points(light.position, point);
	distance = vector_length(v);
	r = set_ray(point, normalize_vector(v));
	list = intersect_world(w, r);
	if (list.total == 0)
		return (FALSE);
	hit = get_hit_intersection(list);
	if (hit && hit->t < distance)
	{
		free_intersection_list(&list);
		return (TRUE);
	}
	free_intersection_list(&list);
	return (FALSE);
}

/**
 * @brief The shade_hit() function will calculate the color of a point of
 * intersection encapsulated in the precomputed values in a given world. It
 * will use the lighting() function to calculate the shading and the
 * is_shadowed() function to check if the point is in shadow or not.
 *
 * @param world the world
 * @param comps the precomputed values of the intersection
 * @param light the light source
 * @return t_vector the color of the point of intersection
 */
t_vector	shade_hit(t_world world, t_comp comps, t_light light)
{
	t_bool	shadow;

	shadow = is_shadowed(world, comps.over_point, light);
	return (lighting(comps.xs->object->material, light, comps, shadow));
}
