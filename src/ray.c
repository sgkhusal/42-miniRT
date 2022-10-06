/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 12:21:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//Each ray created by your ray tracer will have a starting point called the
//origin, and a vector called the direction which says where it points.
t_ray	set_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = normalize_vector(direction);
	return (ray);
}

/**
 * @brief To find the position, you multiply the ray’s direction by distance to
 * find the total distance traveled, and then add that to the ray’s origin.
 * Equivalent a S = So + V * t, where S is the point position in the ray at a
 * given distance, So is the ray origin, V is the ray direction and t is the
 * distance.
 *
 * @param ray ray to find the position
 * @param distance distance to find the position
 * @return t_point the point position in the ray at a given distance
 */
t_point	ray_position(t_ray ray, double distance)
{
	t_point	position;
	double	x;
	double	y;
	double	z;

	x = ray.origin.x + ray.direction.x * distance;
	y = ray.origin.y + ray.direction.y * distance;
	z = ray.origin.z + ray.direction.z * distance;
	position = set_point(x, y, z);
	return (position);
}
