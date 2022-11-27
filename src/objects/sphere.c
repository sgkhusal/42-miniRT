/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/27 18:08:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Will create a new sphere by allocating memory and setting the given
 * values to the struct.
 *
 * @param color The color of the sphere.
 * @return t_sphere* The created sphere.
 */
t_sphere	*create_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		minirt_malloc_error("create_sphere");
	sphere->center = set_point(0, 0, 0);
	sphere->radius = 1.0;
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
t_xs	sphere_intersection(t_ray ray, t_object *o)
{
	t_xs		xs;
	t_bhaskara	bhaskara;
	t_vector	sphere_to_ray;

	xs.count = 0;
	sphere_to_ray = subtract_points(ray.origin, o->shape.sphere->center);
	bhaskara.a = scalar_product(ray.direction, ray.direction);
	bhaskara.b = 2 * scalar_product(ray.direction, sphere_to_ray);
	bhaskara.c = scalar_product(sphere_to_ray, sphere_to_ray) - 1;
	bhaskara.delta = pow(bhaskara.b, 2) - 4 * bhaskara.a * bhaskara.c;
	if (bhaskara.delta < 0)
		return (xs);
	xs.count = 2;
	xs.t1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	xs.t2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	return (xs);
}
