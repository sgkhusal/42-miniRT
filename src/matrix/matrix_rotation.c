/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/30 16:03:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Creates a rotation matrix around the x axis. It will rotate a point
 * or vector around the x axis by the given angle (in radians). The rotation
 * will appear to be clockwise around the x axis when viewed along the x axis,
 * toward the negative end. This is the left-hand rule.
 *
 * @param radians angle of rotation in radians
 * @return t_matrix the resulting rotation matrix
 */
t_matrix	rotation_x_matrix(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[1][1] = cos(radians);
	rotation.matrix[1][2] = -sin(radians);
	rotation.matrix[2][1] = sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

/**
 * @brief Creates a rotation matrix around the y axis. It will rotate a point
 * or vector around the y axis by the given angle (in radians). The rotation
 * will appear to be clockwise around the y axis when viewed along the y axis,
 * toward the negative end. This is the left-hand rule.
 *
 * @param radians angle of rotation in radians
 * @return t_matrix the resulting rotation matrix
 */
t_matrix	rotation_y_matrix(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][2] = sin(radians);
	rotation.matrix[2][0] = -sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

/**
 * @brief Creates a rotation matrix around the z axis. It will rotate a point
 * or vector around the z axis by the given angle (in radians). The rotation
 * will appear to be clockwise around the z axis when viewed along the z axis,
 * toward the negative end. This is the left-hand rule.
 *
 * @param radians angle of rotation in radians
 * @return t_matrix the resulting rotation matrix
 */
t_matrix	rotation_z_matrix(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][1] = -sin(radians);
	rotation.matrix[1][0] = sin(radians);
	rotation.matrix[1][1] = cos(radians);
	return (rotation);
}
