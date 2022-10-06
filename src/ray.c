/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 00:21:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//Each ray created by your ray tracer will have a starting point called the
//origin, and a vector called the direction which says where it points.
t_ray	create_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

// To find the position, you multiply the ray’s direction by distance to find
// the total distance traveled, and then add that to the ray’s origin.
// equivalent a S = So + V * t
// ray.origin + ray.direction * distance
// returns the point position in the ray at a given distance
t_point	ray_position(t_ray ray, double distance) // precisa mudar o nome dessa função
{
	t_point		position;
	t_point		initial_position;
	t_vector	distance_traveled;

	initial_position = ray.origin;
	distance_traveled = multiply_vector_by_scalar(ray.direction, distance);
	position = add_point_and_vector(initial_position, distance_traveled);
	return (position);
}
