/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 11:37:03 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Creates a new plane by allocating memory for it and setting its
 * default values. It is assumed, to make calculations easier, that the plane
 * will be horizontally oriented (normal vector will be (0, 1, 0)) and that the
 * plane will be centered in the origin (center point will be (0, 0, 0)).
 *
 * @return t_plane* The created plane.
 */
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

/**
 * @brief This function will calculate the intersection between a ray and a
 * plane. If the ray is parallel to the plane, there is no intersection. If the
 * ray origin is coplanar with the plane and the ray direction is parallel to
 * the plane, there is no intersection because all points are intersections and
 * the plane is invisible. If the ray origin is in the plane the ray misses the
 * plane.
 *
 * @param ray is the ray that will intersect the plane.
 * @param p the plane that will be intersected by the ray.
 * @return t_xs the t_xs struct.
 */
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
