/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:48:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 13:50:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rgb_to_int(short int red, short int green, short int blue) // provavelmente não vamos usar
{
	t_color	color;

	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	color.rgb[3] = 0;
	color.rgb[2] = red;
	color.rgb[1] = green;
	color.rgb[0] = blue;
	return (color.color);
}

t_color	set_color(short int red, short int green, short int blue)
{
	t_color	color;

	printf("param red: %d, param green: %d, param blue: %d", red, green, blue);
	color.rgb[0] = blue;
	color.rgb[1] = green;
	color.rgb[2] = red;
	color.rgb[3] = 0;
	printf("color: %x\n", color.color);
	printf("red: %d, green: %d, blue: %d\n", color.rgb[2] + 256, color.rgb[1], color.rgb[0]);
	return (color);
} /* 0 - 255 (-128 - 127) */

t_vector	multiply_colors(t_vector a, t_vector b)
{
	t_vector	color;

	color.x = a.x * b.x;
	color.y = a.y * b.y;
	color.z = a.z * b.z;
	return (color);
}

t_vector	normalize_color(t_color color)
{
	t_vector	normalized_color;

	if (color.rgb[2] < 0)
		normalized_color.x = (color.rgb[2] + 256) / 255.0;
	else
		normalized_color.x = color.rgb[2] / 255.0;
	if (color.rgb[1] < 0)
		normalized_color.y = (color.rgb[1] + 256) / 255.0;
	else
		normalized_color.y = color.rgb[1] / 255.0;
	if (color.rgb[0] < 0)
		normalized_color.z = (color.rgb[0] + 256) / 255.0;
	else
		normalized_color.z = color.rgb[0] / 255.0;
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
		return (set_vector(0, 0, 0));
	//printf("object type: %d\n", hit->object->type);
	//printf("material color: %f, %f, %f\n", hit->object->material.normalized_color.x, hit->object->material.normalized_color.y, hit->object->material.normalized_color.z);
	comps = prepare_computations(ray, hit);
	color = shade_hit(world, comps);
	free_intersection_list(&list);
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	//printf("color: %f %f %f\n", color.x, color.y, color.z);
	return (color);
}
