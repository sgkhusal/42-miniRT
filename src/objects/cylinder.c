/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:10:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/08 17:23:30 by sguilher         ###   ########.fr       */
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
	cylinder->transform = identity_matrix(4);
	cylinder->inverse = identity_matrix(4);
	cylinder->transpose_inverse = identity_matrix(4);
	cylinder->material = set_material();
	return (cylinder);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free_matrix(cylinder->transform);
	free_matrix(cylinder->inverse);
	free_matrix(cylinder->transpose_inverse);
	free(cylinder);
}

t_xs	cylinder_intersection(t_ray ray, t_cylinder c) // tem que normalizar a direção do raio antes de ele vir como nos testes!!
{
	t_xs		xs;
	t_ray		transformed_ray;
	t_bhaskara	bhaskara;

	xs.count = 0;
	transformed_ray = transform_ray(ray, c.inverse);
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
