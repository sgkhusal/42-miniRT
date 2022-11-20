/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:03:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/16 19:0503 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
We receive the point p in the world space
To calculate the normal, we need to transform the point p to the object space
After the calculation, we transform the normal in the object space to the world
space
world_normal.w = 0 to avoid translation transformations affecting the normal.
*/
t_vector	sphere_normal_at(t_object *s, t_point world_point)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;

	object_point = multiply_matrix_by_point(s->inverse, world_point);
	object_normal = subtract_points(object_point, s->shape.sphere->center);
	world_normal = multiply_matrix_by_vector(
				s->transpose_inverse, object_normal);
	world_normal.w = 0;
	return (normalize_vector(world_normal));
}

// os pontos estão sendo passados em relação ao mundo e não ao objeto
t_vector	cylinder_normal_at(t_object *c, t_point world_point)
{
	//t_point	object_point;
	double	dist;

	//object_point = multiply_matrix_by_point(c->inverse, p);
	dist = pow(world_point.x, 2) + pow(world_point.z, 2);
	if (dist < 1 && world_point.y >= c->shape.cylinder->max - EPSILON)
		return (set_vector(0, 1, 0));
	else if (dist < 1 && world_point.y <= c->shape.cylinder->min + EPSILON)
		return (set_vector(0, -1, 0));
	else
		return (set_vector(world_point.x, 0, world_point.z)); // normalizar?
		//na parte da esfera fala que tem que normalizar
}
