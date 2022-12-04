/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 09:27:44 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will take the string containing the cylinder
 * information from the scene file and go through each of them to check if
 * they are valid. Cylinder will receive a x, y, z coordinate, a normal vector,
 * a diameter, a height and a color. The x, y, z coordinate must be a valid
 * coordinate, the normal vector must be a valid vector from 0 to 1, the
 * diameter must be a positive double, the height must be a positive double
 * and the color must be a valid RGB coordinate from 0 to 255.
 *
 * @param infos the information of the cylinder
 * @return int 0 if the information is valid, 1 otherwise
 */
static int	validate_cylinder_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[3]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[4]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[5]) == ERROR)
		return (ERROR);
	return (OK);
}

/**
 * @brief This function will set the transformation matrices for the
 * cylinder. It will set the translation matrix, the rotation matrix and the
 * scaling matrix. Using the set_transform function, it will apply the result
 * of the multiplication of the matrices to the transformation matrix of the
 * cylinder. After that, it will free the matrices.
 *
 * @param o the object cylinder
 * @param center the center of the cylinder
 * @param radius the radius of the cylinder
 * @param orientation the orientation of the cylinder
 */
static void	set_cylinder_matrixes(t_object *o, t_point center, double radius,
									t_vector orientation)
{
	t_matrix	translation;
	t_matrix	scaling;
	t_matrix	rotation;
	t_matrix	tmp;

	translation = translation_matrix(center.x, center.y, center.z);
	scaling = scaling_matrix(radius, 1, radius);
	rotation = get_rotation_matrix(orientation);
	tmp = multiply_matrix(translation, rotation);
	set_transform(o, multiply_matrix(tmp, scaling));
	free_matrix(translation);
	free_matrix(scaling);
	free_matrix(rotation);
	free_matrix(tmp);
}

/**
 * @brief This function will create the cylinder object. It will allocate
 * memory for the cylinder and transform the information from the scene file
 * into the cylinder properties. It will also set the transformation matrix
 * and the minimum and maximum values for the cylinder (used for the caps).
 * If any error occurs, it will free the memory allocated for the cylinder. If
 * the information is valid, it will append the cylinder to the scene.
 *
 * @param objs the list of objects
 * @param infos the information of the cylinder from the scene file
 * @param status the status of the parsing
 */
static void	create_and_append_cylinder(t_object **objs, char **infos,
	int *status)
{
	t_object	*cy;
	double		radius;
	double		half_height;
	t_point		center;
	t_vector	orientation;

	cy = create_object(CYLINDER, create_cylinder());
	center = transform_coordinates(infos[1], status);
	orientation = transform_orientation(infos[2], status);
	radius = transform_double(infos[3], status) / 2;
	half_height = transform_double(infos[4], status) / 2;
	cy->shape.cylinder->max = half_height;
	cy->shape.cylinder->min = -half_height;
	cy->material.color = transform_color(infos[5], status);
	set_cylinder_matrixes(cy, center, radius, orientation);
	if (*status == ERROR)
		free_objects(&cy);
	else
		append_object(objs, cy);
}

/**
 * @brief This is the main handler for the cylinder. It will split the line
 * containing the cylinder information from the scene file and check if the
 * information is valid. If it is valid, it will create the cylinder object
 * and append it to the scene. If it is not valid, it will set the status to
 * ERROR.
 *
 * @param line the line containing the cylinder information
 * @param objs the list of objects
 * @return int 0 if the parsing is successful, 1 otherwise
 */
int	handle_cylinder(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_cylinder"));
	if (total_infos(infos) != 6)
		status = print_error_msg2("to many or few arguments for cylinder: \
		[center] [height orientation] [diameter] [height] [RGB color]: ", line);
	else if (validate_cylinder_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_cylinder(objs, infos, &status);
	free_array(infos);
	return (status);
}
