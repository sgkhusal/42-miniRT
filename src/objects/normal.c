/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:03:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 18:18:27 by sguilher         ###   ########.fr       */
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

t_vector	cylinder_normal_at(t_object *o, t_point p)
{
	(void)(*o);
	return (set_vector(p.x, 0, p.z));
}
