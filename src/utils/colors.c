/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:48:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 13:12:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	multiply_colors(t_vector a, t_vector b)
{
	t_vector	color;

	color.x = a.x * b.x;
	color.y = a.y * b.y;
	color.z = a.z * b.z;
	return (color);
}

t_vector	normalize_color(double red, double green, double blue)
{
	t_vector	normalized_color;

	normalized_color.x = red / 255.0;
	normalized_color.y = green / 255.0;
	normalized_color.z = blue / 255.0;
	normalized_color.w = 0;
	return (normalized_color);
}

t_color	transform_vector_to_color(t_vector color)
{
	t_color	rgb;

	rgb.rgb[2] = (int)(color.x * 255);
	rgb.rgb[1] = (int)(color.y * 255);
	rgb.rgb[0] = (int)(color.z * 255);
	return (rgb);
}

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
	color = shade_hit(world, comps);
	free_intersection_list(&list);
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}
