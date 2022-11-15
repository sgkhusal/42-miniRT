/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:48:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/13 17:06:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	ray_for_pixel_test(t_camera camera, double x, double y, t_ray expected)
{
	t_ray	result;
	static int	n = 0;

	printf(GREY "ray_for_pixel_test %d" END, n);
	result = ray_for_pixel(camera, x, y);
	if (check_equal_points(result.origin, expected.origin)
		&& check_equal_vectors(result.direction, expected.direction))
		printf(GREEN " OK" END "\n");
	else
		printf(RED " KO" END "\n");
	n++;
}

void	ray_for_pixel_tests(void)
{
	t_camera	camera;
	t_ray		ray;

	camera = set_camera(M_PI / 2, 201, 101);
	ray = set_ray(set_point(0, 0, 0), set_vector(0, 0, -1));
	ray_for_pixel_test(camera, 100, 50, ray);
	ray = set_ray(set_point(0, 0, 0), set_vector(0.66519, 0.33259, -0.66851));
	ray_for_pixel_test(camera, 0, 0, ray);
	free_matrix(camera.transform);
	free_matrix(camera.inverse);
	camera.transform = multiply_matrix(rotation_y_matrix(M_PI / 4),
		translation_matrix(0, -2, 5));
	camera.inverse = inverse_matrix(camera.transform);
	ray = set_ray(set_point(0, 2, -5), set_vector(sqrt(2)/2, 0, -sqrt(2)/2));
	ray_for_pixel_test(camera, 100, 50, ray);
	free_matrix(camera.transform);
	free_matrix(camera.inverse);
}

