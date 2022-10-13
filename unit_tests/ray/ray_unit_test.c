/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_unit_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:29:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/13 19:20:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	set_ray_test(void)
{
	t_ray		ray;
	t_point		origin;
	t_vector	direction;

	printf(GREY "set_ray_test 1: ");
	origin = set_point(1, 2, 3);
	direction = set_vector(4, 5, 6);
	ray = set_ray(origin, direction);
	if (ray.origin.x == 1 && ray.origin.y == 2 && ray.origin.z == 3
		&& ray.direction.x == 4 && ray.direction.y == 5
		&& ray.direction.z == 6)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
}

static void	ray_position_test(t_ray ray, double distance, t_point expected)
{
	t_point		position;
	static int	n = 1;

	printf(GREY "ray_position_test %d: ", n);
	position = ray_position(ray, distance);
	if (check_double_values(position.x, expected.x)
		&& check_double_values(position.y, expected.y)
		&& check_double_values(position.z, expected.z)
		&& check_double_values(position.w, expected.w))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

static void	ray_position_test_cases1(void)
{
	t_ray		ray;

	ray.origin = set_point(2, 3, 4);
	ray.direction = set_vector(1, 0, 0);
	ray_position_test(ray, 0, set_point(2, 3, 4));
	ray_position_test(ray, 1, set_point(3, 3, 4));
	ray_position_test(ray, -1, set_point(1, 3, 4));
	ray_position_test(ray, 2.5, set_point(4.5, 3, 4));
	ray.direction = set_vector(0, 1, 0);
	ray_position_test(ray, 0, set_point(2, 3, 4));
	ray_position_test(ray, 1, set_point(2, 4, 4));
	ray_position_test(ray, -1, set_point(2, 2, 4));
	ray_position_test(ray, 2.5, set_point(2, 5.5, 4));
	ray.direction = set_vector(0, 0, 1);
	ray_position_test(ray, 0, set_point(2, 3, 4));
	ray_position_test(ray, 1, set_point(2, 3, 5));
	ray_position_test(ray, -1, set_point(2, 3, 3));
	ray_position_test(ray, 2.5, set_point(2, 3, 6.5));
}

static void	ray_position_test_cases2(void)
{
	t_ray		ray;

	ray.origin = set_point(2, 3, 4);
	ray.direction = set_vector(2, 0, 0);
	ray_position_test(ray, 0, set_point(2, 3, 4));
	ray_position_test(ray, 1, set_point(4, 3, 4));
	ray_position_test(ray, -1, set_point(0, 3, 4));
	ray_position_test(ray, 2.5, set_point(7, 3, 4));
	ray.direction = set_vector(1, 1, 0);
	ray_position_test(ray, 0, set_point(2, 3, 4));
	ray_position_test(ray, 1, set_point(3, 4, 4));
	ray_position_test(ray, -1, set_point(1, 2, 4));
	ray_position_test(ray, 2.5, set_point(4.5, 5.5, 4));
}

void	ray_tests(void)
{
	printf(YELLOW "Ray tests: \n" END);
	set_ray_test();
	ray_position_test_cases1();
	ray_position_test_cases2();
	transform_ray_test_cases();
}
