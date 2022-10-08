/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:29:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 16:17:06 by sguilher         ###   ########.fr       */
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
