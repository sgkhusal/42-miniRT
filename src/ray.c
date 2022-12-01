/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 10:05:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Each ray created by the ray tracer will have a starting point called
 * the origin, and a vector called the direction which says where it points to.
 * The direction vector needs to be normalized so that the ray can be used to
 * calculate the intersection with the objects.
 *
 * @param origin The origin of the ray.
 * @param direction The direction of the ray.
 * @return t_ray The t_ray struct containing the point of the origin and the
 * normalized direction vector.
 */

t_ray	set_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
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

/**
 * @brief To avoid changing the sphere's properties, which would make the calculations
 * more complex, the transformation can be applied to the ray instead so that the
 * sphere can be treated as if it were centered at the origin and had a radius of 1
 * and by transforming the ray, the illusion of the sphere transforming is created.
 * 
 * @param ray ray to be transformed
 * @param m transformation matrix
 * @return t_ray transformed ray
 */
t_ray	transform_ray(t_ray ray, t_matrix m)
{
	t_ray	transformed_ray;

	transformed_ray = set_ray(multiply_matrix_by_point(m, ray.origin),
			multiply_matrix_by_vector(m, ray.direction));
	return (transformed_ray);
}

/**
 * @brief the ray_for_pixel function calculates the ray that passes through the
 * center of a given pixel on the canvas. It does the job of calculating the
 * location of the pixel on the canvas from the ray casted from the camera.
 * 
 * @param cam camera
 * @param x pixel x coordinate
 * @param y pixel y coordinate
 * @return t_ray ray that passes through the center of a given pixel on the canvas
 */
t_ray	ray_for_pixel(t_camera cam, double x, double y) // up doc
{
	double	xoffset;
	double	yoffset;
	t_point	world;
	t_point	pixel;
	t_ray	ray;

	xoffset = (x + 0.5) * cam.pixel_size;
	yoffset = (y + 0.5) * cam.pixel_size;
	world = set_point(cam.half_width - xoffset, cam.half_height - yoffset, -1);
	pixel = multiply_matrix_by_point(cam.inverse, world);
	ray.origin = cam.origin;
	ray.direction = normalize_vector(subtract_points(pixel, ray.origin));
	return (ray);
}
