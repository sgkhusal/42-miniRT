/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/04 15:32:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//Each ray created by your ray tracer will have a starting point called the origin,
//and a vector called the direction which says where it points.
t_ray	*create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		minirt_malloc_error("create_ray");
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

// To find the position, you multiply the ray’s direction by distance to find the total
// distance traveled, and then add that to the ray’s origin.
// equivalent a S = So + V * t
t_tuple	*position(t_ray *ray, double distance)
{
	t_tuple	*position;
	t_tuple	initial_position;
	t_tuple	*distance_traveled;

	initial_position = *ray->origin;
	distance_traveled = multiply_tuple_by_scalar(*(ray->direction), distance);
	position = add_tuples(initial_position, *distance_traveled);
	free(distance_traveled);
	return (position);
}
