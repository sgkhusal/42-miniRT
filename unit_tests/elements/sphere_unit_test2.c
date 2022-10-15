/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_unit_test2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:04:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/14 21:05:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transformed_sphere_test1(void)
{
	t_intersection_list	list;
	t_sphere			*s;
	t_matrix			transform;
	t_ray				ray;

	printf(GREY "transformed_sphere_test 1: " END);
	transform = scaling_matrix(2, 2, 2);
	s = create_sphere(set_color(255, 0, 0));
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	set_transform(s, transform);
	list.head = NULL;
	list.last = NULL;
	list.total = 0;
	sphere_intersection(ray, *s, &list);
	if (list.total == 2 && check_double_values(list.head->t, 3)
		&& check_double_values(list.head->next->t, 7))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(list.head->next);
	free(list.head);
	free_sphere(s);
}

void	transformed_sphere_test2(void)
{
	t_intersection_list	list;
	t_sphere			*s;
	t_matrix			transform;
	t_ray				ray;

	printf(GREY "transformed_sphere_test 2: " END);
	transform = translation_matrix(5, 0, 0);
	s = create_sphere(set_color(255, 0, 0));
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	set_transform(s, transform);
	list.head = NULL;
	list.last = NULL;
	list.total = 0;
	sphere_intersection(ray, *s, &list);
	if (list.total == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_sphere(s);
}

void	transformed_sphere_test(void)
{
	transformed_sphere_test1();
	transformed_sphere_test2();
}
