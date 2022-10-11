/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/11 19:54:220 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Will create a new sphere by allocating memory and setting the given
 * values to the struct.
 *
 * @param center The center point of the sphere.
 * @param radius The radius of the sphere.
 * @param color The color of the sphere.
 * @return t_sphere* The created sphere.
 */
t_sphere	*create_sphere(t_point center, double radius, t_color color)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		minirt_malloc_error("create_sphere");
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

/**
 * @brief Gets the intersections between a ray and a sphere.
 *
 * @param ray is the ray that will intersect the sphere.
 * @param sphere is the sphere that will be intersected by the ray.
 * @param projected_center sphere center projection into the ray direction.
 * @param projected_vector vector from ray origin to sphere's projected center.
 * @return t_xs a struct containing all intersections of the ray with the
 * sphere. If the ray doesn't intersect with any point of the sphere,the count
 * variable of t_xs struct will be 0. If the ray is tangent to the sphere, the
 * count variable will be 2 andt1 and t2 willhave the same value.
 */
t_xs	sphere_intersection(t_ray ray, t_sphere sphere)
{
	t_xs			xs;
	double			projected_center;
	t_point			projected_vector;
	double			x_sphere;
	double			y_sphere;

	projected_center = scalar_product(subtract_points(sphere.center,
				ray.origin), ray.direction);
	projected_vector = ray_position(ray, projected_center);
	y_sphere = vector_length(subtract_points(sphere.center,
				projected_vector));
	if (y_sphere > sphere.radius)
		xs.count = 0;
	else
	{
		xs.count = 2;
		x_sphere = sqrt(pow(sphere.radius, 2) - pow(y_sphere, 2));
		xs.t1 = projected_center - x_sphere;
		xs.t2 = projected_center + x_sphere;
	}
	return (xs);
}

/**
 * @brief The hit will be the closest intersection point with a t
 * greater than 0.
 *
 * @param t1 is the first intersection point.
 * @param t2 is the second intersection point.
 * @return double the hit.
 */
double	get_hit(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	if (t1 < t2)
		return (t1);
	return (t2);
}
