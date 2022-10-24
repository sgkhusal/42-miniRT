/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:28:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/23 20:46:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	transform_color(char *rgb_str, int *status)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	if (ft_strlen(rgb_str) > 11)
	{
		*status = print_error_msg2("invalid color range: ", rgb_str);
		return (set_color(0, 0, 0));
	}
	rgb = ft_split(rgb_str, ',');
	if (!rgb)
	{
		*status = print_error_msg("malloc error on transform_color");
		return (set_color(0, 0, 0));
	}
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red > 255 || green > 255 || blue > 255)
		*status = print_error_msg2("invalid color range: ", rgb_str);
	free_array(rgb);
	return (set_color(red, green, blue));
}

// ambient lighting ratio in range [0.0,1.0]
// the light brightness ratio in range [0.0,1.0]
double	transform_ratio(char *ratio_str, int *status)
{
	double	ratio;

	/* if (ft_strlen(ratio_str) > 11)
	{
		*status = print_error_msg2("invalid ratio range: ", ratio_str);
		return (0);
	} */
	ratio = 0.2;
	//ratio = ft_atod(ratio_str);
	if (ratio < 0 || ratio > 1)
		*status = print_error_msg2("invalid ratio range: ", ratio_str);
	return (ratio);
}

t_point	transform_coordinates(char *xyz_str, int *status)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	/* if (ft_strlen(xyz_str) > 11)
	{
		*status = print_error_msg2("invalid xyz range: ", xyz_str);
		return (set_point(0, 0, 0));
	} */
	xyz = ft_split(xyz_str, ',');
	if (!xyz)
	{
		*status = print_error_msg("malloc error on transform_coordinates");
		return (set_point(0, 0, 0));
	}
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	if (x < -1000 || x > 1000 || y < -1000 || y > 1000 || z < -1000
		|| z > 1000) // verificar que range vamos deixar
		*status = print_error_msg2("invalid coordinates range: ", xyz_str);
	free_array(xyz);
	return (set_point(x, y, z));
}

// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
t_vector	transform_orientation(char *xyz_str, int *status)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	/* if (ft_strlen(xyz_str) > 11)
	{
		*status = print_error_msg2("invalid xyz range: ", xyz_str);
		return (set_vector(0, 0, 0));
	} */
	xyz = ft_split(xyz_str, ',');
	if (!xyz)
	{
		*status = print_error_msg("malloc error on transform_orientation");
		return (set_vector(0, 0, 0));
	}
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	if (x < -1 || x > 1 || y < -1 || y > 1 || z < -1 || z > 1)
		*status = print_error_msg2(
			"invalid 3d normalized orientation vector range: ", xyz_str);
	free_array(xyz);
	return (set_vector(x, y, z));
}

// sphere diameter
// cylinder diameter and height
double	transform_double(char *str, int *status)
{
	double	d;

	/* if (ft_strlen(str) > 11)
	{
		*status = print_error_msg2("invalid number range: ", str);
		return (0);
	} */
	d = 2;
	//d = ft_atod(str);
	if (d < -1000 || d > 1000) // verificar que range vamos deixar
		*status = print_error_msg2("invalid number range: ", str);
	return (d);
}
