/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:58 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 09:41:46 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will take the string containing the information of the
 * sphere and go through it, validating the information. Sphere will receive
 * a x, y, z coordinate, a diameter and a color. The x, y, z coordinate must be
 * a valid coordinate, the diameter must be a positive double and the color
 * must be a valid RGB coordinate from 0 to 255.
 *
 * @param infos the information of the sphere
 * @return int 0 if the information is valid, 1 otherwise
 */
static int	validate_sphere_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

/**
 * @brief This function will set the transformation matrices for the sphere.
 * It will set the translation matrix and the scaling matrix. Using the
 * set_transform function, it will apply the result of the multiplication of
 * the matrices to the transformation matrix of the sphere. After that, it will
 * free the matrices.
 *
 * @param o the object sphere
 * @param center the center of the sphere
 * @param radius the radius of the sphere
 */
static void	set_sphere_matrixes(t_object *o, t_point center, double radius)
{
	t_matrix	translation;
	t_matrix	scaling;

	translation = translation_matrix(center.x, center.y, center.z);
	scaling = scaling_matrix(radius, radius, radius);
	set_transform(o, multiply_matrix(translation, scaling));
	free_matrix(translation);
	free_matrix(scaling);
}

/**
 * @brief This function will create the sphere object. It will allocate memory
 * for the sphere and transform the information from the scene file into the
 * sphere properties. It will also set the transformation matrix for the sphere.
 * If any error occurs, it will free the memory allocated for the sphere. If the
 * information is valid, it will append the sphere to the list of objects.
 *
 * @param objs the list of objects
 * @param infos the information of the sphere from the scene file
 * @param status the status of the parsing
 */
static void	create_and_append_sphere(t_object **objs, char **infos, int *status)
{
	t_object	*s;
	double		radius;
	t_point		center;

	s = create_object(SPHERE, create_sphere());
	center = transform_coordinates(infos[1], status);
	radius = transform_double(infos[2], status) / 2;
	s->material.color = transform_color(infos[3], status);
	set_sphere_matrixes(s, center, radius);
	if (*status == ERROR)
		free_objects(&s);
	else
		append_object(objs, s);
}

/**
 * @brief This is the main handle function for the sphere. It will split the
 * line containing the information of the sphere from the scene file and check
 * if the information is valid. If it is, it will create the sphere and append
 * it to the list of objects. If it is not, it will set the status to ERROR.
 *
 * @param line the line containing the information of the sphere
 * @param objs the list of objects
 * @return int 0 if the parsing is successful, 1 otherwise
 */
int	handle_sphere(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_sphere"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments in sphere: \
		[center point] [diameter] [RGB color]: ", line);
	else if (validate_sphere_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_sphere(objs, infos, &status);
	free_array(infos);
	return (status);
}
