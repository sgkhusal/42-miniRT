/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:48:40 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 12:02:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function calculates the rotation matrix of an object when
 * combining rotation around the x and y axis is needed.
 *
 * @param orientation The orientation of the object.
 * @return t_matrix The resulting rotation matrix.
 */
static t_matrix	get_x_y_rotation(t_vector orientation)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation;

	rotation_x = rotation_x_matrix(M_PI / 2);
	rotation_y = rotation_y_matrix(atan(orientation.x / orientation.z));
	rotation = multiply_matrix(rotation_y, rotation_x);
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	return (rotation);
}

/**
 * @brief This function calculates the rotation matrix of an object when
 * combining rotation around the x and z axis is necessary.
 *
 * @param orientation orientation vector of the object
 * @return t_matrix the resulting rotation matrix
 */
static t_matrix	get_z_x_rotation(t_vector orientation)
{
	t_matrix	rotation_x;
	t_matrix	rotation_z;
	t_matrix	rotation;

	rotation_x = rotation_x_matrix(atan(orientation.z / orientation.y));
	rotation_z = rotation_z_matrix(atan(-orientation.x / orientation.y));
	rotation = multiply_matrix(rotation_z, rotation_x);
	free_matrix(rotation_x);
	free_matrix(rotation_z);
	return (rotation);
}

/**
 * @brief This function will handle the correct rotation matrix to be applied
 * to the plane or the cylinder based on the orientation given by the user on
 * the scene file. It will return the rotation matrix to be applied to the
 * plane or the cylinder or send to the get_x_y_rotation or get_z_x_rotation
 * function to combine the rotation matrices.
 *
 * @param orientation orientation vector of the object
 * @return t_matrix rotation matrix to be applied to the plane or the cylinder
 */
t_matrix	get_rotation_matrix(t_vector orientation)
{
	if (check_equal_vectors(set_vector(0, 1, 0), orientation))
		return (identity_matrix(4));
	else if (check_equal_vectors(set_vector(0, -1, 0), orientation))
		return (rotation_x_matrix(M_PI));
	else if (check_equal_vectors(set_vector(1, 0, 0), orientation))
		return (rotation_z_matrix(-M_PI / 2));
	else if (check_equal_vectors(set_vector(-1, 0, 0), orientation))
		return (rotation_z_matrix(M_PI / 2));
	else if (check_equal_vectors(set_vector(0, 0, 1), orientation))
		return (rotation_x_matrix(M_PI / 2));
	else if (check_equal_vectors(set_vector(0, 0, -1), orientation))
		return (rotation_x_matrix(-M_PI / 2));
	if (check_double_values(orientation.y, 0))
		return (get_x_y_rotation(orientation));
	else
		return (get_z_x_rotation(orientation));
}
