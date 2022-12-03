/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:48:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 15:00:221 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Multiplication of two colors is a operation that is used to blend
 * two colors together. For example, it can be used to get the color of a
 * surface when it is hit by a light source of another color.
 *
 * @param a first color
 * @param b second color
 * @return t_vector resulting color
 */
t_vector	multiply_colors(t_vector a, t_vector b)
{
	t_vector	color;

	color.x = a.x * b.x;
	color.y = a.y * b.y;
	color.z = a.z * b.z;
	return (color);
}

/**
 * @brief This function is used to normalize a color. It is used to limit the
 * color values to the range of 0 to 1. Behaves just like the normalize_vector
 * function but taking into account the rgb values.
 *
 * @param red red value
 * @param green green value
 * @param blue blue value
 * @return t_vector normalized color
 */
t_vector	normalize_color(double red, double green, double blue)
{
	t_vector	normalized_color;

	normalized_color.x = red / 255.0;
	normalized_color.y = green / 255.0;
	normalized_color.z = blue / 255.0;
	normalized_color.w = 0;
	return (normalized_color);
}

/**
 * @brief This function will convert an vector into a rgb color. It will be used
 * to convert the color of a pixel into a color that can be displayed on the
 * screen.
 *
 * @param color vector color
 * @return t_color rgb color
 */
t_color	transform_vector_to_color(t_vector color)
{
	t_color	rgb;

	rgb.rgb[2] = (int)(color.x * 255);
	rgb.rgb[1] = (int)(color.y * 255);
	rgb.rgb[0] = (int)(color.z * 255);
	return (rgb);
}

t_vector get_total_color(t_world world, t_comp comps)
{
	t_light		*light;
	t_vector	total_color;
	t_vector	color;

	total_color = multiply_colors(comps.xs->object->material.color,
		comps.xs->object->material.ambient);
	light = world.lights;
	while (light)
	{
		color = shade_hit(world, comps, *light);
		total_color = add_vectors(total_color, color);
		light = light->next;
	}
	return (total_color);
}

/**
 * @brief The color_at function will return the color in a intersection resulted
 * from a ray intersecting the world. It will return the color black if there is
 * no intersection.
 *
 * @param world the world struct
 * @param ray the casted ray
 * @return t_vector resulting color
 */
t_vector	color_at(t_world world, t_ray ray)
{
	t_intersection_list	list;
	t_intersection		*hit;
	t_comp				comps;
	t_vector			color;

	list = intersect_world(world, ray);
	if (list.total == 0)
		return (set_vector(0, 0, 0));
	hit = get_hit_intersection(list);
	if (!hit)
	{
		free_intersection_list(&list);
		return (set_vector(0, 0, 0));
	}
	comps = prepare_computations(ray, hit);
	color = get_total_color(world, comps);
	free_intersection_list(&list);
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}
