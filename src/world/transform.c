/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/13 15:49:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *o, t_matrix transform)
{
	free_matrix(o->transform);
	o->transform = transform;
	free_matrix(o->inverse);
	o->inverse = inverse_matrix(o->transform);
	free_matrix(o->transpose_inverse);
	o->transpose_inverse = transposed_matrix(o->inverse);
}

t_matrix	view_transform(t_point from, t_point to, t_vector up)
{
	t_vector	forward;
	t_vector	left;
	t_vector	true_up;
	t_matrix	translation;
	t_matrix	orientation;
	t_matrix	transform;

	forward = normalize_vector(subtract_points(to, from));
	left = cross_product(forward, normalize_vector(up));
	true_up = cross_product(left, forward);
	orientation = identity_matrix(4);
	orientation.matrix[0][0] = left.x;
	orientation.matrix[0][1] = left.y;
	orientation.matrix[0][2] = left.z;
	orientation.matrix[1][0] = true_up.x;
	orientation.matrix[1][1] = true_up.y;
	orientation.matrix[1][2] = true_up.z;
	orientation.matrix[2][0] = -forward.x;
	orientation.matrix[2][1] = -forward.y;
	orientation.matrix[2][2] = -forward.z;
	translation = translation_matrix(-from.x, -from.y, -from.z);
	transform = multiply_matrix(orientation, translation);
	free_matrix(translation);
	free_matrix(orientation);
	return (transform);
}
