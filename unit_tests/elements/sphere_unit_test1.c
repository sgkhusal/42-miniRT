/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_unit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:29:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/13 19:51:46 by elrara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_sphere_test(void)
{
	t_sphere	*sphere;
	t_matrix	identity;
	t_color		color;

	printf(GREY "create sphere test: " END);
	color = set_color(255, 0, 0);
	sphere = create_sphere();
	identity = identity_matrix(4);
	if (sphere->center.x == 0 && sphere->center.y == 0 && sphere->center.z == 0
		&& sphere->radius == 1
		&& check_equal_matrices(sphere->transform, identity)
		&& check_equal_matrices(sphere->inverse, identity)
		&& check_equal_matrices(sphere->transpose_inverse, identity)
		&& sphere->material.ambient == 0.1 && sphere->material.diffuse == 0.9
		&& sphere->material.shininess == 200
		&& sphere->material.specular == 0.9)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(identity);
	free_sphere(sphere);
}

void	sphere_intersection_test(t_sphere *s, t_ray ray, double t1, double t2)
{
	t_xs				xs;
	static int			n = 1;

	printf(GREY "sphere_intersection_test %d: " END, n);
	xs = sphere_intersection(ray, *s);
	if (xs.count == 2 && check_double_values(xs.t1, t1)
		&& check_double_values(xs.t2, t2))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	sphere_transform_test(void)
{
	t_sphere	*sphere;
	t_matrix	transform;

	printf(GREY "sphere_transform_test: " END);
	sphere = create_sphere();
	transform = translation_matrix(2, 3, 4);
	set_transform_sphere(sphere, transform);
	if (check_equal_matrices(sphere->transform, transform))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_sphere(sphere);
}

void	sphere_no_intersection_test(t_sphere *sphere, t_ray ray)
{
	t_xs		xs;

	printf(GREY "sphere_no_intersection_test: " END);
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
	sphere = create_sphere();
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, 4.0, 6.0);
	ray = set_ray(set_point(0, 1, -5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, 5.0, 5.0);
	ray = set_ray(set_point(0, 2, -5), set_vector(0, 0, 1));
	sphere_no_intersection_test(sphere, ray);
	ray = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, -1.0, 1.0);
	ray = set_ray(set_point(0, 0, 5), set_vector(0, 0, 1));
	sphere_intersection_test(sphere, ray, -6.0, -4.0);
	sphere_transform_test();
	transformed_sphere_test();
	free_sphere(sphere);
}
