/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:11:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 16:07:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	check_hit_value(double hit, double t)
{
	if (t <= 0 + EPSILON)
		return (hit);
	if (hit <= t && hit > 0)
		return (hit);
	return (t);
}

/**
 * @brief The hit will be the closest intersection point with a t
 * greater than 0.
 *
 * @param t1 is the first intersection point.
 * @param t2 is the second intersection point.
 * @return double the hit.
 */
/* if hit < 0, the intersection is behind the camera
 * if hit = 0, the intersection is at the camera
 * if hit > 0, the intersection is ahead of the camera
 * the visible intersection is the smaller positive number
 */
t_intersection	*get_hit_intersection(t_intersection_list list)
{
	t_intersection	*aux;
	t_intersection	*hit_intersection;
	double			hit;

	aux = list.head;
	hit = -1;
	hit_intersection = NULL;
	while (aux)
	{
		hit = check_hit_value(hit, aux->t);
		if (hit == aux->t)
			hit_intersection = aux;
		aux = aux->next;
	}
	return (hit_intersection);
}
