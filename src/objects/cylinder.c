/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:10:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/12 00:36:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder *create_cylinder(void)
{
	t_cylinder *cylinder;

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

static void calculate_cylinder_intersection(t_cylinder *c, t_ray ray,
											t_bhaskara bhaskara, t_xs *xs)
{
	double t1;
	double t2;
	double y;

	t1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	t2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	y = ray.origin.y + t1 * ray.direction.y;
	//printf("t1: %f, t2: %f, xs.count: %d, xs.t1 = %f, xs.t2 = %f\n", t1, t2, xs->count, xs->t1, xs->t2);
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

t_bool	check_cap(t_ray ray, double t)
{
	double x;
	double z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= 1);
}

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

t_xs cylinder_intersection(t_ray ray, t_object *c) // tem que normalizar a direção do raio antes de ele vir como nos testes!!
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
