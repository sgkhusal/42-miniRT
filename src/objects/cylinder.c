/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:10:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 16:21:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*create_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		minirt_malloc_error("create_cylinder");
	cylinder->center = set_point(0, 0, 0);
	cylinder->orientation = set_vector(0, 1, 0);
	cylinder->radius = 1.0;
	cylinder->height = 1.0; // infinite height
	return (cylinder);
}

// aqui pode mandar apenas a matriz inversa...
t_xs	cylinder_intersection(t_ray ray, t_object *o) // tem que normalizar a direção do raio antes de ele vir como nos testes!!
{
	t_xs		xs;
	t_ray		transformed_ray;
	t_bhaskara	bhaskara;

	xs.count = 0;
	transformed_ray = transform_ray(ray, o->inverse);
	bhaskara.a = pow(transformed_ray.direction.x, 2)
		+ pow(transformed_ray.direction.z, 2);
	if (check_double_values(bhaskara.a, 0))
		return (xs);
	bhaskara.b = 2 * transformed_ray.origin.x * transformed_ray.direction.x
			+ 2 * transformed_ray.origin.z * transformed_ray.direction.z;
	bhaskara.c = pow(transformed_ray.origin.x, 2)
		+ pow(transformed_ray.origin.z, 2) - 1;
	bhaskara.delta = pow(bhaskara.b, 2) - 4 * bhaskara.a * bhaskara.c;
	if (bhaskara.delta < 0)
		xs.count = 0;
	else
	{
		xs.count = 2;
		xs.t1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
		xs.t2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	}
	return (xs);
}

t_vector	get_cylinder_color(t_ray ray, t_object *o, t_light light,
					t_intersection *hit)
{
	t_vector			color;
	t_vector			normal;
	t_vector			eye;
	t_point				point;

	point = ray_position(ray, hit->t);
	normal = cylinder_normal_at(o, point);
	eye = negative_vector((ray.direction));
	color = lighting(o->material, light, point, normal, eye);
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}
