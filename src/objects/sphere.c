/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/12/03 11:34:11 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Will create a new sphere by allocating memory to it. To make things
 * easier, it is assumed that the sphere is centered at the origin of the
 * world coordinate system and that its radius is 1.0.
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
 * @brief This function will get the t_xs struct containing the intersections
 * between a ray and a sphere. For this, it will first check if the ray
 * intersects with the sphere by calculating the discriminant which is
 * equivalent to the baskhara.delta. If the discriminant is negative, the ray
 * doesn't intersect with the sphere. Then, it will calculate the t1 and t2
 * values and return a t_xs struct containing the intersections and the count
 * of intersections. If the ray is tangent to the sphere, the count variable
 * will be 2 and t1 and t2 will have the same value.
 *
 * @param ray is the ray that will intersect the sphere.
 * @param o the object that will be intersected by the ray, in this case a
 * sphere.
 * @return t_xs the t_xs struct.
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
