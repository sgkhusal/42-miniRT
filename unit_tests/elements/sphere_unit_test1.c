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
	t_matrix	transform;
	t_color		color;

	printf(GREY "create sphere test 1: " END);
	color = set_color(255, 0, 0);
	sphere = create_sphere(color);
	transform = identity_matrix(4);
	if (sphere->center.x == 0 && sphere->center.y == 0 && sphere->center.z == 0
		&& sphere->radius == 1 && sphere->color.color == 0xFF0000
		&& check_equal_matrices(sphere->transform, transform)
		&& check_equal_matrices(sphere->inverse, transform))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(transform);
	free_sphere(sphere);
}

void	sphere_intersection_test(t_sphere *s, t_ray ray, double t1, double t2)
{
	t_intersection_list	list;
	static int			n = 1;

	printf(GREY "sphere_intersection_test %d: " END, n);
	list.head = NULL;
	list.last = NULL;
	sphere_intersection(ray, *s, &list);
	if (list.total == 2 && check_double_values(list.head->t, t1)
		&& check_double_values(list.head->next->t, t2)
		&& check_double_values(list.last->t, t2)
		&& list.head->object == SPHERE && list.last->object == SPHERE
		&& list.head->next->object == SPHERE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free(list.head);
	free(list.last);
}

void	sphere_transform_test(void)
{
	t_sphere	*sphere;
	t_matrix	transform;

	printf(GREY "sphere_transform_test 1: " END);
	sphere = create_sphere(set_color(255, 0, 0));
	transform = translation_matrix(2, 3, 4);
	set_transform(sphere, transform);
	if (check_equal_matrices(sphere->transform, transform))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_sphere(sphere);
}

void	sphere_no_intersection_test(t_sphere *sphere, t_ray ray)
{
	t_intersection_list	list;

	printf(GREY "sphere_no_intersection_test 1: " END);
	list.head = NULL;
	list.last = NULL;
	list.total = 0;
	sphere_intersection(ray, *sphere, &list);
	if (list.total == 0)
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
	sphere = create_sphere(set_color(255, 0, 0));
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
	normal_tests();
	free_sphere(sphere);
}
