/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/06 12:04:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//pow and sqrt are functions from math.h
/* t = scalar_product(centro da esfera - ray_origin, ray_direction);
y = length(centro da esfera - position(ray_origin + t * ray_direction));
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
 * @brief
 *
 * @param ray is the ray that will intersect the sphere.
 * @param sphere is the sphere that will be intersected by the ray.
 * @param projected_center sphere center projection into the ray direction.
 * @param projected_vector vector from ray origin to sphere's projected center.
 * @return t_intersection the t_interction struct.
 */
t_intersection	sphere_intersection(t_ray ray, t_sphere sphere)
{
	t_intersection	intersection;
	double			projected_center;
	t_point			projected_vector;
	double			x_sphere;
	double			y_sphere;

	/*printf("center_sphere: %f, %f, %f\n", sphere.center.x, sphere.center.y, sphere.center.z);
	printf("radius: %f\n", sphere.radius);
	printf("color: %X\n", sphere.color.color);
	printf("origin: %f, %f, %f\n", ray.origin.x, ray.origin.y, ray.origin.z);
	printf("direction: %f, %f, %f\n", ray.direction.x, ray.direction.y, ray.direction.z); */
	t_vector sub = subtract_points(sphere.center, ray.origin); //ok
	printf("sub: %f, %f, %f\n", sub.x, sub.y, sub.z);
	projected_center = scalar_product(sub, ray.direction); //ok
	printf("projected_center: %f\n", projected_center);
	projected_vector = ray_position(ray, projected_center);
	printf("projected_vector: %f, %f, %f\n", projected_vector.x, projected_vector.y, projected_vector.z);
	y_sphere = vector_length(subtract_points(sphere.center,
		projected_vector));
	if (y_sphere > sphere.radius)
	{
		printf("No intersection\n");
		intersection.count = 0;
		return (intersection);
	}
	x_sphere = sqrt(pow(sphere.radius, 2) - pow(y_sphere, 2));
	intersection.t1 = projected_center - x_sphere;
	intersection.t2 = projected_center + x_sphere;
	intersection.count = 2;
	return (intersection);
}
