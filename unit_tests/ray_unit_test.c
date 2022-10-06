/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_unit_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:29:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 21:39:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_ray_test()
{
	t_ray		ray;
	t_point		origin;
	t_vector	direction;

	printf(GREY "set_ray_test 1: ");
	set_point(&origin, 1, 2, 3);
	set_vector(&direction, 4, 5, 6);
	set_ray(&ray, origin, direction);
	if (ray.origin.x == 1 && ray.origin.y == 2 && ray.origin.z == 3
		&& ray.direction.x == 4 && ray.direction.y == 5 && ray.direction.z == 6)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
}

void	create_ray_test()
{
	t_ray	*ray;
	t_point		origin;
	t_vector	direction;

	printf(GREY "create_ray_test 1: ");
	set_point(&origin, 1, 2, 3);
	set_vector(&direction, 4, 5, 6);
	ray = create_ray(origin, direction);
	if (ray->origin.x == 1 && ray->origin.y == 2 && ray->origin.z == 3
		&& ray->direction.x == 4 && ray->direction.y == 5 && ray->direction.z == 6)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(ray);
}

void	ray_position_test(t_ray ray, int distance, int x, int y, int z)
{
	t_point		*position;
	static int	n = 1;

	printf(GREY "ray_position_test %d: ", n);
	position = ray_position(ray, distance);
	if (position->x == x && position->y == y &&
		position->z == z && position->w == 1)
			printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(position);
	n++;
}

void	ray_tests(void)
{
	t_ray		ray;

	printf(YELLOW "Ray tests: \n" END);
	set_ray_test();
	create_ray_test();
	set_point(&ray.origin, 2, 3, 4);
	set_vector(&ray.direction, 1, 0, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 3, 3, 4);
	ray_position_test(ray, -1, 1, 3, 4);
	ray_position_test(ray, 2.5, 4.5, 3, 4);
	set_vector(&ray.direction, 0, 1, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 2, 4, 4);
	ray_position_test(ray, -1, 2, 2, 4);
	ray_position_test(ray, 2.5, 2, 5.5, 4);
	set_vector(&ray.direction, 0, 0, 1);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 2, 3, 5);
	ray_position_test(ray, -1, 2, 3, 3);
	ray_position_test(ray, 2.5, 2, 3, 6.5);
	set_vector(&ray.direction, 2, 0, 0);
	ray_position_test(ray, 0, 2, 3, 4);
	ray_position_test(ray, 1, 5, 3, 4);
	ray_position_test(ray, -1, -2, 3, 4);
	ray_position_test(ray, 2.5, 5, 3, 4);
	// acho que sempre vamos ter que normalizar o vetor direção do raio
}
