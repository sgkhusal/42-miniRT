/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_unit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:29:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 20:16:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_sphere_test(void)
{
	t_sphere	*sphere;
	t_point		center;
	t_color		color;
	double		radius;

	printf(GREY "create sphere test 1: " END);
	center = set_point(0, 0, 0);
	color = set_color(255, 0, 0);
	radius = 1;
	sphere = create_sphere(center, radius, color);
	if (sphere->center.x == 0 && sphere->center.y == 0 && sphere->center.z == 0
		&& sphere->radius == 1 && sphere->color.color == 0xFF0000)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(sphere);
}

void	sphere_intersection_test(t_sphere *sphere, t_ray ray, double t1,
				double t2, int count)
{
	t_xs	xs;
	static int		n = 1;

	printf(GREY "sphere_intersection_test %d: " END, n);
	xs = sphere_intersection(ray, *sphere);
	if (xs.count == count && check_double_values(xs.t1, t1)
		&& check_double_values(xs.t2, t2))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	sphere_no_intersection_test(t_sphere *sphere, t_ray ray)
{
	t_xs	xs;

	printf(GREY "sphere_no_intersection_test 1: " END);
	xs = sphere_intersection(ray, *sphere);
	if (xs.count == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	sphere_tests(void)
{
	t_sphere	*sphere;
	t_ray		ray;

	printf(YELLOW "Sphere tests: " END "\n");
	create_sphere_test();
	sphere = create_sphere(set_point(0, 0, 0), 1, set_color(255, 0, 0));
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, 4.0, 6.0, 2);
	ray = set_ray(set_point(0, 1, -5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, 5.0, 5.0, 2);
	ray = set_ray(set_point(0, 2, -5), set_vector(0, 0, 1));
	sphere_no_intersection_test(sphere, ray);
	ray = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, -1.0, 1.0, 2);
	ray = set_ray(set_point(0, 0, 5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, -6.0, -4.0, 2);
	free(sphere);
	sphere = create_sphere(set_point(4, 3, 0), 1, set_color(255, 0, 0));
	ray = set_ray(set_point(0, 0, 0), set_vector(1, 1, 0));
	sphere_intersection_test(sphere, ray, 4.242641, 5.656854, 2);
	free(sphere);
}
