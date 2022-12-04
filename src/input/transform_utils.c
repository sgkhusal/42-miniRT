/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:28:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 12:52:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will take the color string received as a parameter from
 * the scene file and will convert it to a t_vector coordinate. First, it will
 * separate the string into three substrings, each one representing a color
 * value. Then, it will convert each substring to an integer and store it in a
 * t_vector coordinate after normalizing it. If the color value is not between
 * 0 and 255, it will return an error.
 *
 * @param color_str string with the color values
 * @param status pointer to the status variable
 * @return t_vector coordinate with the color values
 */
t_vector	transform_color(char *color_str, int *status)
{
	char	**rgb;
	double	red;
	double	green;
	double	blue;

	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	rgb = parse_input(color_str, ',', 3, status);
	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	if (ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[1]) > 3 || ft_strlen(rgb[2]) > 3)
	{
		*status = print_error_msg2("invalid color range [0-255]: ", color_str);
		free_array(rgb);
		return (set_vector(0, 0, 0));
	}
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red > 255 || green > 255 || blue > 255)
		*status = print_error_msg2("invalid color range [0-255]: ", color_str);
	free_array(rgb);
	return (normalize_color(red, green, blue));
}

/**
 * @brief This function will take the ambient light ratio and transform it to a
 * double value. If the ratio is not between 0 and 1, it will return an error.
 * If the total number of characters (including points and commas) is greater
 * than 7, it will return an error also.

 * @param ratio_str string with the ambient light ratio
 * @param status pointer to the status variable
 * @return double value with the ambient light ratio converted to a double value
 */
double	transform_ratio(char *ratio_str, int *status)
{
	double	ratio;
	char	*cpy;

	if (*status == ERROR)
		return (0);
	if (ft_strlen(ratio_str) > 7)
	{
		*status = print_error_msg2("invalid ratio range [0.0,1]: ", ratio_str);
		return (0);
	}
	cpy = ft_strdup(ratio_str);
	ratio = ft_atod(cpy);
	free(cpy);
	if (ratio < 0 || ratio > 1)
		*status = print_error_msg2("invalid ratio range [0.0,1]: ", ratio_str);
	return (ratio);
}

/**
 * @brief This function will take the string with the coordinates and transform
 * it to a t_point coordinate. First, it will separate the string into three
 * substrings, each one representing a coordinate. Then, it will convert each
 * substring to a double and store it in a t_point point coordinate. If the
 * number of characters (including points and commas) is greater than 11, it
 * will return an error also.
 *
 * @param xyz_str string with the coordinates
 * @param status pointer to the status variable
 * @return t_point point with the coordinates
 */
t_point	transform_coordinates(char *xyz_str, int *status)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	if (*status == ERROR)
		return (set_point(0, 0, 0));
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
	if (x < -1000 || x > 1000 || y < -1000 || y > 1000 || z < -1000 || z > 1000)
		*status = print_error_msg2("invalid coordinates range [-1000,1000]: ",
				xyz_str);
	free_array(xyz);
	return (set_point(x, y, z));
}

/**
 * @brief This function will take the string with the orientation vector and
 * transform it to a t_vector coordinate. First, it will separate the string
 * into three substrings, each one representing a coordinate. Then, it will
 * convert each substring to a double and store it in a t_vector coordinate.
 * Must be whitin the range [-1,1] for each x,y,z axis (0.0,0.0,1.0).
 *
 * @param xyz_str string with the orientation vector
 * @param status pointer to the status variable
 * @return t_vector coordinate with the orientation vector
 */
t_vector	transform_orientation(char *xyz_str, int *status)
{
	char	**xyz;
	double	x;
	double	y;
	double	z;

	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	xyz = parse_input(xyz_str, ',', 3, status);
	if (*status == ERROR)
		return (set_vector(0, 0, 0));
	if (ft_strlen(xyz[0]) > 9 || ft_strlen(xyz[1]) > 9 || ft_strlen(xyz[2]) > 9)
	{
		*status = print_error_msg2("invalid orientation vector range or size: ",
				xyz_str);
		free_array(xyz);
		return (set_vector(0, 0, 0));
	}
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	if (!check_double_values(vector_length(set_vector(x, y, z)), 1))
		*status = print_error_msg2("orientation vector is not normalized: ",
				xyz_str);
	free_array(xyz);
	return (set_vector(x, y, z));
}

/**
 * @brief This function will take the string with the diameter of the sphere or
 * cylinder and also the cylinder's height and transform it to a double value.
 * We chose to not allow values greater than 1000 for the diameter and height
 * to limit the size of the object. If the total number of characters (including
 * points and commas) is greater than 11, it will return an error also.
 *
 * @param str string with the diameter or height
 * @param status pointer to the status variable
 * @return double value with the diameter or height converted to a double value
 */
double	transform_double(char *str, int *status)
{
	double	d;
	char	*cpy;

	if (*status == ERROR)
		return (0);
	if (ft_strlen(str) > 11)
	{
		*status = print_error_msg2("invalid number range: ", str);
		return (0);
	}
	cpy = ft_strdup(str);
	d = ft_atod(cpy);
	free(cpy);
	if (d <= 0 || d > 1000)
		*status = print_error_msg2("invalid number range: ", str);
	return (d);
}
