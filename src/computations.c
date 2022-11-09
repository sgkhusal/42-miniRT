/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:03:15 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/29 15:46:221 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

enum e_bool is_inside(t_comp *comp)
{
	if (scalar_product(comp->normalv, comp->eyev) < 0)
	{
		comp->normalv = negative_vector(comp->normalv);
		return (TRUE);
	}
	return (FALSE);
}

t_comp	prepare_computations(t_ray ray, t_intersection *intersect)
{
	t_comp	comp;

	comp.xs = intersect;
	comp.point = ray_position(ray, intersect->t);
	comp.eyev = negative_vector(ray.direction);
	if (intersect->object->type == SPHERE)
		comp.normalv = sphere_normal_at(intersect->object, comp.point);
	comp.inside = is_inside(&comp);
	return (comp);
}

