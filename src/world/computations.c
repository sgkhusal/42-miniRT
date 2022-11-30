/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:03:15 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 1640:08 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will check whether the hit occurs inside the object or
 * outside of it. If the hit is inside the object, the normal vector will be
 * inverted.
 *
 * @param comp computation structure from prepare_computations function
 * @return t_bool true if the hit is inside the object, false otherwise
 */
t_bool	is_inside(t_comp *comp)
{
	if (scalar_product(comp->normalv, comp->eyev) < 0)
	{
		comp->normalv = negative_vector(comp->normalv);
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief This function will prepare the computation structure to be used in
 * the shading functions. It will make things easier because these information
 * can be reused in several functions.
 * Ray, point, eyev and normalv are in the world space.
 *
 * @param ray ray that hit the object
 * @param intersect intersect structure containing intersected object and t,
 * which is the distance from the ray origin to the hit point
 * @return t_comp computation structure
 */
t_comp	prepare_computations(t_ray ray, t_intersection *intersect)
{
	t_comp	comp;

	comp.xs = intersect;
	comp.point = ray_position(ray, intersect->t);
	comp.eyev = negative_vector(ray.direction);
	if (intersect->object->type == SPHERE)
		comp.normalv = sphere_normal_at(intersect->object, comp.point);
	else if (intersect->object->type == PLANE)
		comp.normalv = plane_normal_at(intersect->object, comp.point);
	else if (intersect->object->type == CYLINDER)
		comp.normalv = cylinder_normal_at(intersect->object, comp.point);
	comp.inside = is_inside(&comp);
	comp.over_point = add_point_and_vector(comp.point,
			multiply_vector_by_scalar(comp.normalv, EPSILON));
	return (comp);
}
