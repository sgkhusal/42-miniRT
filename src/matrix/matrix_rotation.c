/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 17:00:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* The rotation will appear to be clockwise around the corresponding axis when
viewed along that axis, toward the negative end. */
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
