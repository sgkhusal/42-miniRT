/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:28:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 12:29:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**parse_input(char *line, char c, int size_expected, int *status)
{
	char	**parsed;

	parsed = ft_split(line, c);
	if (!parsed)
		*status = print_error_msg2("malloc error on parse_input: ", line);
	else if (total_infos(parsed) != size_expected)
	{
		free_array(parsed);
		*status = print_error_msg2("to many or few arguments in ", line);
	}
	return (parsed);
}

t_vector	transform_color(char *color_str, int *status)
{
	char	**rgb;
	double	red;
	double	green;
	double	blue;

	rgb = parse_input(color_str, ',', 3, status);
	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	if (ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[1]) > 3 || ft_strlen(rgb[2]) > 3)
	{
		*status = print_error_msg2("invalid color range: ", color_str);
		free_array(rgb);
		return (set_vector(0, 0, 0));
	}
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	printf("red: %f, green: %f, blue: %f\n", red, green, blue);
	if (red > 255 || green > 255 || blue > 255)
		*status = print_error_msg2("invalid color range: ", color_str);
	free_array(rgb);
	return (set_vector(red / 255, green / 255, blue /255));
}

// ambient lighting ratio in range [0.0,1.0]
// the light brightness ratio in range [0.0,1.0]
double	transform_ratio(char *ratio_str, int *status)
{
	double	ratio;
	char	*cpy;

	if (ft_strlen(ratio_str) > 7) // 0.00001
	{
		*status = print_error_msg2("invalid ratio range: ", ratio_str);
		return (0);
	}
	cpy = ft_strdup(ratio_str);
	ratio = ft_atod(cpy);
	free(cpy);
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

	xyz = parse_input(xyz_str, ',', 3, status);
	if (*status == ERROR)
		return (set_point(0, 0, 0));
	if (ft_strlen(xyz[0]) > 11 || ft_strlen(xyz[1]) > 11
		|| ft_strlen(xyz[2]) > 11)
	{
		*status = print_error_msg2("invalid coordinates range: ", xyz_str);
		free_array(xyz);
		return (set_point(0, 0, 0));
	}
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	// verificar que range vamos deixar
	if (x < -1000 || x > 1000 || y < -1000 || y > 1000 || z < -1000 || z > 1000)
		*status = print_error_msg2("invalid coordinates range: ", xyz_str);
	free_array(xyz);
	return (set_point(x, y, z));
}

// ∗ 3d normalized orientation vector.
// In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
t_vector	transform_orientation(char *xyz_str, int *status)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	xyz = parse_input(xyz_str, ',', 3, status);
	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	if (ft_strlen(xyz[0]) > 11 || ft_strlen(xyz[1]) > 11
		|| ft_strlen(xyz[2]) > 11)
	{
		*status = print_error_msg2("invalid orientation vector range: ",
				xyz_str);
		free_array(xyz);
		return (set_vector(0, 0, 0));
	}
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	/* if (vector_length(set_vector(x, y, z)) != 1)
		*status = print_error_msg2("orientation vector is not normalized: ",
				xyz_str); */
	free_array(xyz);
	return (set_vector(x, y, z));
}

// sphere diameter
// cylinder diameter and height
double	transform_double(char *str, int *status)
{
	double	d;
	char	*cpy;

	if (ft_strlen(str) > 11) // acho que a gente pode limitar mais
	{
		*status = print_error_msg2("invalid number range: ", str);
		return (0);
	}
	cpy = ft_strdup(str);
	d = ft_atod(cpy);
	free(cpy);
	if (d < 0 || d > 1000) // verificar que range vamos deixar
		*status = print_error_msg2("invalid number range: ", str);
	return (d);
}
