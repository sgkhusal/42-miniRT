/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:48:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 15:37:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rgb_to_int(short int red, short int green, short int blue)
{
	t_color	color;

	/* if (red < 0 || red > 255)
		red = 255;
	if (green < 0 || green > 255)
		green = 255;
	if (blue < 0 || blue > 255)
		blue = 255; */
	color.rgb[3] = 0;
	color.rgb[2] = red;
	color.rgb[1] = green;
	color.rgb[0] = blue;
	return (color.color);
}

t_color	set_color(short int red, short int green, short int blue)
{
	t_color	color;

	color.rgb[3] = 0;
	color.rgb[2] = red;
	color.rgb[1] = green;
	color.rgb[0] = blue;
	return (color);
}

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

	normalized_color.x = color.rgb[2] / 255.0;
	normalized_color.y = color.rgb[1] / 255.0;
	normalized_color.z = color.rgb[0] / 255.0;
	return (normalized_color);
}
