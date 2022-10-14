/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:09:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/13 20:28:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transform_ray_test(t_ray ray, t_matrix m, t_ray expected)
{
	t_ray		transformed_ray;
	static int	n = 1;

	printf(GREY "transform_ray_test %d: ", n);
	transformed_ray = transform_ray(ray, m);
	if (check_equal_points(transformed_ray.origin, expected.origin)
		&& check_equal_vectors(transformed_ray.direction, expected.direction))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	transform_ray_test_cases(void)
{
	t_ray ray;
	t_ray expected;
	t_matrix m;

	ray.origin = set_point(1, 2, 3);
	ray.direction = set_vector(0, 1, 0);
	m = translation_matrix(3, 4, 5);
	expected.origin = set_point(4, 6, 8);
	expected.direction = set_vector(0, 1, 0);
	transform_ray_test(ray, m, expected);
	free_matrix(m);
	ray.origin = set_point(1, 2, 3);
	ray.direction = set_vector(0, 1, 0);
	m = scaling_matrix(2, 3, 4);
	expected.origin = set_point(2, 6, 12);
	expected.direction = set_vector(0, 3, 0);
	transform_ray_test(ray, m, expected);
	free_matrix(m);
}




