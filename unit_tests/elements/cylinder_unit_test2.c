/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_unit_test2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:53:14 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/11 00:29:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	truncate_cylinder_test(t_object *cy, t_ray ray, int expected_count)
{
	t_xs		xs;
	static int	n = 1;

	printf(GREY "truncate_cylinder_test %d: " END, n);
	xs = cylinder_intersection(ray, cy);
	if (xs.count == expected_count)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	cylinder_end_cap_test(t_object *cy, t_ray ray, int expected_count)
{
	t_xs		xs;
	static int	n = 1;

	printf(GREY "cylinder_end_cap_test %d: " END, n);
	xs = cylinder_intersection(ray, cy);
	if (xs.count == expected_count)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	cylinder_normal_end_cap_test(t_object *c, t_point p, t_vector expected)
{
	static int	n = 1;
	t_vector	result;

	printf(GREY "cylinder_normal_end_cap_test %d: " END, n);
	result = cylinder_normal_at(c, p);
	if (check_equal_vectors(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	cylinder_end_cap_test_cases(t_object *c)
{
	t_ray		ray;

	ray.origin = set_point(0, 3, 0);
	ray.direction = normalize_vector(set_vector(0, -1, 0));
	cylinder_end_cap_test(c, ray, 2);
	ray.origin = set_point(0, 3, -2);
	ray.direction = normalize_vector(set_vector(0, -1, 2));
	cylinder_end_cap_test(c, ray, 2);
	ray.origin = set_point(0, 4, -2);
	ray.direction = normalize_vector(set_vector(0, -1, 1));
	cylinder_end_cap_test(c, ray, 2);
	ray.origin = set_point(0, 0, -2);
	ray.direction = normalize_vector(set_vector(0, 1, 2));
	cylinder_end_cap_test(c, ray, 2);
	ray.origin = set_point(0, -1, -2);
	ray.direction = normalize_vector(set_vector(0, 1, 1));
	cylinder_end_cap_test(c, ray, 2);
	cylinder_normal_end_cap_test(c, set_point(0, 1, 0), set_vector(0, -1, 0));
	cylinder_normal_end_cap_test(c, set_point(0.5, 1, 0), set_vector(0, -1, 0));
	cylinder_normal_end_cap_test(c, set_point(0, 1, 0.5), set_vector(0, -1, 0));
	cylinder_normal_end_cap_test(c, set_point(0, 2, 0), set_vector(0, 1, 0));
	cylinder_normal_end_cap_test(c, set_point(0.5, 2, 0), set_vector(0, 1, 0));
	cylinder_normal_end_cap_test(c, set_point(0, 2, 0.5), set_vector(0, 1, 0));
}

void	truncate_cylinder_test_cases(void)
{
	t_object	*c;
	t_ray		ray;

	c = create_object(CYLINDER, create_cylinder());
	c->shape.cylinder->min = 1;
	c->shape.cylinder->max = 2;
	ray.origin = set_point(0, 1.5, 0);
	ray.direction = normalize_vector(set_vector(0.1, 1, 0));
	truncate_cylinder_test(c, ray, 2);
	ray = set_ray(set_point(0, 3, -5), set_vector(0, 0, 1));
	truncate_cylinder_test(c, ray, 0);
	ray.origin = set_point(0, 0, -5);
	truncate_cylinder_test(c, ray, 0);
	ray.origin = set_point(0, 2, -5);
	truncate_cylinder_test(c, ray, 0);
	ray.origin = set_point(0, 1, -5);
	truncate_cylinder_test(c, ray, 0);
	ray.origin = set_point(0, 1.5, -2);
	truncate_cylinder_test(c, ray, 2);
	cylinder_end_cap_test_cases(c);
	free_objects(&c);
}
