/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:29:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 16:11:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Translation is the process of moving an object by adding or
 * subtracting a value from its coordinates. If, for example, we want to move
 * and point (x, y, z) by (a, b, c), we can do it by adding (a, b, c) to
 * (x, y, z). The translation matrix will take the identity matrix and add the
 * point coordinates to the last column.
 *
 * @param x x coordinate of the point
 * @param y y coordinate of the point
 * @param z z coordinate of the point
 * @return t_matrix resulting translation matrix
 */
t_matrix	translation_matrix(double x, double y, double z)
{
	t_matrix	translation;

	translation = identity_matrix(4);
	translation.matrix[0][3] = x;
	translation.matrix[1][3] = y;
	translation.matrix[2][3] = z;
	return (translation);
}

/**
 * @brief Scaling is the process of changing the size of an object by
 * moving its vertices away from or toward the origin (like a hoberman sphere).
 * The scaling matrix will take the identity matrix and multiply the point
 * coordinates to the diagonal elements. It also can be use to change the
 * length of a vector.
 * Obs: Reflection is a special case of scaling. If you multiply a vector by -1,
 * you will get a vector with the same direction but with a magnitude of -1.
 * This is called a reflection.
 *
 * @param x x coordinate of the point (or vector)
 * @param y y coordinate of the point (or vector)
 * @param z z coordinate of the point (or vector)
 * @return t_matrix resulting scaling matrix
 */
t_matrix	scaling_matrix(double x, double y, double z)
{
	t_matrix	scaling;

	scaling = identity_matrix(4);
	scaling.matrix[0][0] = x;
	scaling.matrix[1][1] = y;
	scaling.matrix[2][2] = z;
	return (scaling);
}

/**
 * @brief Shearing has the effect of changing the shape of an object by
 * moving its vertices along the x, y, or z axis. When applied to a tuple,
 * it will move the x coordinate by the y and z coordinates, the y coordinate
 * by the x and z coordinates, and the z coordinate by the x and y coordinates.
 *
 * @param s the shearing structure which contains the values of each coordinate
 * in proportion to the other two coordinates (for example, x_y means that the
 * x coordinate will be moved by the y coordinate).
 * @return t_matrix resulting shearing matrix
 */
t_matrix	shearing_matrix(t_shearing s)
{
	t_matrix	shearing;

	shearing = identity_matrix(4);
	shearing.matrix[0][1] = s.x_y;
	shearing.matrix[0][2] = s.x_z;
	shearing.matrix[1][0] = s.y_x;
	shearing.matrix[1][2] = s.y_z;
	shearing.matrix[2][0] = s.z_x;
	shearing.matrix[2][1] = s.z_y;
	return (shearing);
}
