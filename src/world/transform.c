/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/20 10:53:50 by sguilher         ###   ########.fr       */
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

void	set_camera_transform(t_camera *cam, t_matrix transform)
{
	free_matrix(cam->transform);
	cam->transform = transform;
	free_matrix(cam->inverse);
	cam->inverse = inverse_matrix(cam->transform);
}

/*
Simulates the eye movement
from: the eye position - default: point(0, 0, 0)
to: the point where the eye is looking at - default: point(0, 0, -1)
up: a vector indicating which direction is up - default: vector(0, 1, 0)
The up vector doesn't need to be normalized and it doesn't need to be
perpendicular to the viewing direction. The function will take care of that.
You only have to point vaguely in the direction you want
*/
t_matrix	view_transform(t_point from, t_vector forward, t_vector up)
{
	t_vector	left;
	t_vector	true_up;
	t_matrix	translation;
	t_matrix	orientation;
	t_matrix	transform;

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
