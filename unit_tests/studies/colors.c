/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:11:06 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 13:12:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rgb_to_int(short int red, short int green, short int blue)
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

	color.rgb[0] = blue;
	color.rgb[1] = green;
	color.rgb[2] = red;
	color.rgb[3] = 0;
	return (color);
}
/* 0 - 255 (-128 - 127) */
