/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:10:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 14:29:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Create a new cylinder object by allocating memory and setting its
 * default values. It is assumed, to make calculations easier, that the
 * cylinder's radius is always 1 and that it will be centered at the origin
 * (0, 0, 0). By default, the cylinder is oriented along the y axis and
 * the height is positive infinity
 *
 * @return t_cylinder* pointer to the new cylinder object
 */
t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		minirt_malloc_error("create_cylinder");
	cylinder->center = set_point(0, 0, 0);
	cylinder->orientation = set_vector(0, 1, 0);
	cylinder->radius = 1.0;
	cylinder->height = INFINITY;
	cylinder->min = -INFINITY;
	cylinder->max = INFINITY;
	return (cylinder);
}

/**
 * @brief Calculates the intersection between a ray and a cylinder considering
 * the cylinder without caps.
 *
 * @param ray ray that will be used to calculate the intersection
 * @param c cylinder that will be used to calculate the intersection
 * @param bhaskara bhaskara struct that will be used to calculate the
 * intersection
 * @param xs t intersection values and total number of intersections
 * @return t_intersection* pointer to the intersection object
 */
static void	calculate_cylinder_intersection(t_cylinder *c, t_ray ray,
											t_bhaskara bhaskara, t_xs *xs)
{
	double	t1;
	double	t2;
	double	y;

	t1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	t2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	y = ray.origin.y + t1 * ray.direction.y;
	if (c->min < y && y < c->max)
	{
		if (xs->count == 0)
			xs->t1 = t1;
		else
			xs->t2 = t1;
		xs->count++;
	}
	y = ray.origin.y + t2 * ray.direction.y;
	if (c->min < y && y < c->max)
	{
		if (xs->count == 0)
			xs->t1 = t2;
		else
			xs->t2 = t2;
		xs->count++;
	}
}

/**
 * @brief the check_cap function checks if the intersection point is inside
 * a radius of 1 . If so, it returns true, otherwise it returns false. This will
 * avoid the problem of duplicate intersections when the ray intersects the
 * end caps
 *
 * @param ray ray that will be used to calculate the intersection
 * @param t intersection value
 * @return t_bool true if the intersection point is inside the radius of 1,
 * otherwise it returns false
 */
t_bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= 1);
}

/**
 * @brief It checks to see if the given ray intersects the end caps of the
 * given cylinder, and adds the points of intersection (if any) to the xs
 * collection.
 *
 * @param ray ray that will be used to calculate the intersection
 * @param c cylinder that will be used to calculate the intersection
 * @param xs t intersection values and total number of intersections
 */
void	cylinder_intersect_caps(t_ray ray, t_cylinder *c, t_xs *xs)
{
	double	t;

	t = (c->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		if (xs->count == 0)
			xs->t1 = t;
		else
			xs->t2 = t;
		xs->count++;
	}
	t = (c->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		if (xs->count == 0)
			xs->t1 = t;
		else if (xs->count == 1)
			xs->t2 = t;
		xs->count++;
	}
}

/**
 * @brief This function will return the cylinder's intersections. It will
 * first check if there are any intersections in the "sides" of the cylinder.
 * If there aren't, it will check if there are any intersections within the end
 * caps of the cylinder using the cylinder_intersect_caps function. If there
 * are intersections to the sides, it will calculate first the intersections of
 * the sides and then the intersections of the end caps (if any).
 *
 * @param ray ray that will be used to calculate the intersection
 * @param c cylinder to be intersected
 * @return t_xs t intersection values and total number of intersections
 */
t_xs	cylinder_intersection(t_ray ray, t_object *c)
{
	t_xs		xs;
	t_bhaskara	bhaskara;

	xs.count = 0;
	bhaskara.a = pow(ray.direction.x, 2)
		+ pow(ray.direction.z, 2);
	if (check_double_values(bhaskara.a, 0))
	{
		cylinder_intersect_caps(ray, c->shape.cylinder, &xs);
		return (xs);
	}
	bhaskara.b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	bhaskara.c = pow(ray.origin.x, 2)
		+ pow(ray.origin.z, 2) - 1;
	bhaskara.delta = pow(bhaskara.b, 2) - 4 * bhaskara.a * bhaskara.c;
	if (bhaskara.delta < 0)
		return (xs);
	else
		calculate_cylinder_intersection(c->shape.cylinder, ray, bhaskara, &xs);
	if (xs.count == 2)
		return (xs);
	cylinder_intersect_caps(ray, c->shape.cylinder, &xs);
	return (xs);
}
