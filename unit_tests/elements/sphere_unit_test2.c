/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_unit_test2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:04:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 14:40:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transformed_sphere_test1(void)
{
	t_xs		xs;
	t_object	*s;
	t_matrix	transform;
	t_ray		ray;

	printf(GREY "transformed_sphere_test 1: " END);
	transform = scaling_matrix(2, 2, 2);
	s = create_object(SPHERE, create_sphere());
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	set_transform(s, transform);
	ray = transform_ray(ray, s->inverse);
	xs.count = 0;
	xs = sphere_intersection(ray, s);
	if (xs.count == 2 && check_double_values(xs.t1, 3)
		&& check_double_values(xs.t2, 7))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&s);
}

void	transformed_sphere_test2(void)
{
	t_xs		xs;
	t_object	*s;
	t_matrix	transform;
	t_ray		ray;

	printf(GREY "transformed_sphere_test 2: " END);
	transform = translation_matrix(5, 0, 0);
	s = create_object(SPHERE, create_sphere());
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	set_transform(s, transform);
	ray = transform_ray(ray, s->inverse);
	xs.count = 0;
	sphere_intersection(ray, s);
	if (xs.count == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&s);
}

void	transformed_sphere_test(void)
{
	transformed_sphere_test1();
	transformed_sphere_test2();
}
