/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:03:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/11 23:50:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	sphere_normal_at(t_object *s, t_point p)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;

	object_point = multiply_matrix_by_point(s->inverse, p);
	object_normal = subtract_points(object_point, s->shape.sphere->center);
	world_normal = normalize_vector(multiply_matrix_by_vector(
				s->transpose_inverse, object_normal));
	return (world_normal);
}

// os pontos estão sendo passados em relação ao mundo e não ao objeto
t_vector	cylinder_normal_at(t_object *o, t_point p)
{
	double	dist;

	dist = pow(p.x, 2) + pow(p.z, 2);
	if (dist < 1 && p.y >= o->shape.cylinder->max - EPSILON)
		return (set_vector(0, 1, 0));
	else if (dist < 1 && p.y <= o->shape.cylinder->min + EPSILON)
		return (set_vector(0, -1, 0));
	else
		return (set_vector(p.x, 0, p.z));
}
