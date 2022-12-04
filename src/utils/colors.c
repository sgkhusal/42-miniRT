/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:48:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 11:55:41 by sguilher         ###   ########.fr       */
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
