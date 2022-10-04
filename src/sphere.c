/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/04 19:00:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//pow and sqrt are functions from math.h
/* t = scalar_product(centro da esfera - ray_origin, ray_direction);
y = length(centro da esfera - position(ray_origin + t * ray_direction));
*/

t_sphere	*create_sphere(t_tuple *center, double radius, t_color *color)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		minirt_malloc_error("create_sphere");
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = *color;
	free(color);
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
t_intersection	*sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	t_intersection	*intersection;
	double			projected_center;
	t_tuple			*projected_vector;
	double			x_sphere;
	double			y_sphere;

	intersection = malloc(sizeof(t_intersection));
	if (!intersection)
		minirt_malloc_error("create_intersection");
	projected_center = scalar_product(*(subtract_tuples(*sphere->center,
		*ray->origin)), *ray->direction);
	printf("projected_center: %f\n", projected_center);
	projected_vector = ray_position(ray, projected_center);
	y_sphere = tuple_length(subtract_tuples(*sphere->center,
		*projected_vector));
	if (y_sphere > sphere->radius)
	{
		printf("No intersection\n");
		intersection->count = 0;
		return (intersection);
	}
	x_sphere = sqrt(pow(sphere->radius, 2) - pow(y_sphere, 2));
	intersection->t1 = projected_center - x_sphere;
	intersection->t2 = projected_center + x_sphere;
	intersection->count = 2;
	return (intersection);
}
