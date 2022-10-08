/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:29:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 15:26:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	translation_matrix(double x, double y, double z)
{
	t_matrix	translation;

	translation = identity_matrix(4);
	translation.matrix[0][3] = x;
	translation.matrix[1][3] = y;
	translation.matrix[2][3] = z;
	return (translation);
}

t_matrix	scaling_matrix(double x, double y, double z)
{
	t_matrix	scaling;

	scaling = identity_matrix(4);
	scaling.matrix[0][0] = x;
	scaling.matrix[1][1] = y;
	scaling.matrix[2][2] = z;
	return (scaling);
}

/* The rotation will appear to be clockwise around the corresponding axis when
viewed along that axis, toward the negative end. */
t_matrix	rotation_x(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[1][1] = cos(radians);
	rotation.matrix[1][2] = -sin(radians);
	rotation.matrix[2][1] = sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

t_matrix	rotation_y(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][2] = sin(radians);
	rotation.matrix[2][0] = -sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

t_matrix	rotation_z(double radians)
{
	t_matrix	rotation;

	rotation = identity_matrix(4);
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][1] = -sin(radians);
	rotation.matrix[1][0] = sin(radians);
	rotation.matrix[1][1] = cos(radians);
	return (rotation);
}
