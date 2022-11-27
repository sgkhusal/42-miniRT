/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 14:55:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*create_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		minirt_malloc_error("create_plane");
	plane->point = set_point(0, 0, 0);
	plane->orientation = set_vector(0, 1, 0);
	return (plane);
}

// if ray is parallel to plane, there is no intersection, if the ray origin is
// coplanar with the plane and the ray direction is parallel to the plane, there
// is no intersection because all points are intersections and the plane is
// invisible
t_xs	plane_intersection(t_ray ray, t_object *p)
{
	t_xs		xs;

	(void)p;
	if (fabs(ray.direction.y) < EPSILON
		|| check_double_values(ray.origin.y, p->shape.plane->point.y))
	{
		xs.count = 0;
		return (xs);
	}
	xs.t1 = -ray.origin.y / ray.direction.y;
	xs.count = 1;
	return (xs);
}
