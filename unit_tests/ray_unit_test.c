/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_unit_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:29:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 00:14:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_ray_test(void)
{
	t_ray		ray;
	t_point		origin;
	t_vector	direction;

	printf(GREY "create_ray_test 1: ");
	origin = create_point(1, 2, 3);
	direction = create_vector(4, 5, 6);
	ray = create_ray(origin, direction);
	if (ray.origin.x == 1 && ray.origin.y == 2 && ray.origin.z == 3
		&& ray.direction.x == 4 && ray.direction.y == 5 && ray.direction.z == 6)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
}

void	ray_position_test(t_ray ray, double distance, double x, double y,
							double z)
{
	t_point		position;
	static int	n = 1;

	printf(GREY "ray_position_test %d: ", n);
	position = ray_position(ray, distance);
	if (position.x - x > -0.00001 && position.x - x < 0.00001
		&& position.y - y > -0.00001 && position.y - y < 0.00001
		&& position.z - z > -0.00001 && position.z - z < 0.00001
		&& position.w == 1)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	ray_tests(void)
{
	t_ray		ray;

	printf(YELLOW "Ray tests: \n" END);
	create_ray_test();
	ray.origin = create_point(2, 3, 4);
	ray.direction = create_vector(1, 0, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 3, 3, 4);
	ray_position_test(ray, -1, 1, 3, 4);
	ray_position_test(ray, 2.5, 4.5, 3, 4);
	ray.direction = create_vector(0, 1, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 2, 4, 4);
	ray_position_test(ray, -1, 2, 2, 4);
	ray_position_test(ray, 2.5, 2, 5.5, 4);
	ray.direction = create_vector(0, 0, 1);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 2, 3, 5);
	ray_position_test(ray, -1, 2, 3, 3);
	ray_position_test(ray, 2.5, 2, 3, 6.5);
	ray.direction = create_vector(2, 0, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 4, 3, 4);
	ray_position_test(ray, -1, 0, 3, 4);
	ray_position_test(ray, 2.5, 7, 3, 4);
	ray.direction = create_vector(1, 1, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 3, 4, 4);
	ray_position_test(ray, -1, 1, 2, 4);
	ray_position_test(ray, 2.5, 4.5, 5.5, 4);
}
// acho que sempre vamos ter que normalizar o vetor direção do raio
