/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:11:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 11:32:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function takes two intersections, one of which is the current
 * hit, compares them and returns the closest one, which is the one that will be
 * the new hit.
 *
 * @param hit The current hit.
 * @param t intersection to compare with the current hit.
 * @return double The distance to the closest hit.
 */
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
 * greater than 0. If hit < 0, the intersection is behind the camera, if
 * hit = 0, the intersection is at the camera position, and if hit > 0,
 * the intersection is in front of the camera.
 * The visible intersection is the one that is closest to the camera, the
 * smaller positive t value.
 *
 * @param t1 is the first intersection point.
 * @param t2 is the second intersection point.
 * @return double the hit.
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
