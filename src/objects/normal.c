/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:03:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/08 18:01:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	sphere_normal_at(t_sphere *s, t_point p)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;

	object_point = multiply_matrix_by_point(s->inverse, p);
	object_normal = subtract_points(object_point, s->center);
	world_normal = normalize_vector(multiply_matrix_by_vector(
				s->transpose_inverse, object_normal));
	return (world_normal);
}

t_vector	cylinder_normal_at(t_cylinder *c, t_point p)
{
	(void)(*c);
	return (set_vector(p.x, 0, p.z));
}
