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

/**
 * @brief This funciton will calculate the normal of a sphere. To calculate the
 * normal, we need to transform the point p to the object space. After the
 * calculation, we transform the normal in the object space to the world space.
 *
 * @param s the sphere
 * @param world_point the point in the world space
 * @return t_vector the normal vector of the sphere
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

/**
 * @brief Calculates the normal of a plane. First, checks if the point is in
 * one of the end caps or or if it lies on the cylinder itself.
 * If it is in one of the end caps, they are planes, which means an end cap has
 * the same normal at every point on it
 * If it is on the cylinder itself, the normal is calculated by taking the
 * point in question and removing the y component
 * To calculate the normal, we need to transform the point p to the object
 * space. After the calculation, we transform the normal in the object space
 * to the world space.
 *
 * @param c the cylinder
 * @param world_point the point in the world space
 * @return t_vector the normal vector of the cylinder
 */
t_vector	cylinder_normal_at(t_object *c, t_point world_point)
{
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;
	double		dist;

	object_point = multiply_matrix_by_point(c->inverse, world_point);
	dist = pow(object_point.x, 2) + pow(object_point.z, 2);
	if (dist < 1 && object_point.y >= c->shape.cylinder->max - EPSILON)
		object_normal = set_vector(0, 1, 0);
	else if (dist < 1 && object_point.y <= c->shape.cylinder->min + EPSILON)
		object_normal = set_vector(0, -1, 0);
	else
		object_normal = set_vector(object_point.x, 0, object_point.z);
	world_normal = multiply_matrix_by_vector(c->transpose_inverse,
			object_normal);
	world_normal.w = 0;
	return (normalize_vector(world_normal));
}

/**
 * @brief Calculates the normal of a plane. Because the plane has no curvature
 * the normal is constant everywhere. To calculate the normal, we need to
 * transform the point p to the object space. After the calculation, we
 * transform the normal in the object space to the world space.
 *
 * @param p The plane.
 * @param world_point The point in the world space.
 * @return t_vector The normal vector of the plane.
 */
t_vector	plane_normal_at(t_object *p, t_point world_point)
{
	t_vector	object_normal;
	t_vector	world_normal;

	(void)world_point;
	object_normal = p->shape.plane->orientation;
	world_normal = multiply_matrix_by_vector(
			p->transpose_inverse, object_normal);
	return (normalize_vector(world_normal));
}
