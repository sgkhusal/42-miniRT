/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:09:05 by elraira-          #+#    #+#             */
/*   Updated: 2022/12/03 16:52:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

t_world	default_world(void)
{
	t_world		world;
	t_object	*o1;
	t_object	*o2;
	t_light		*l;

	world.lights = NULL;
	l = create_point_light(set_point(-10, 10, -10),
		set_vector(1, 1, 1));
	append_light(&world.lights, l);
	world.objects = NULL;
	o1 = NULL;
	o2 = NULL;
	o1 = create_object(SPHERE, create_sphere());
	o1->material.color = set_vector(0.8, 1.0, 0.6);
	o1->material.diffuse = 0.7;
	o1->material.specular = 0.2;
	append_object(&(world.objects), o1);
	o2 = create_object(SPHERE, create_sphere());
	set_transform(o2, scaling_matrix(0.5, 0.5, 0.5));
	append_object(&(world.objects), o2);
	return (world);
}

void	intersect_world_test(void)
{
	t_world				world;
	t_ray				ray;
	t_intersection_list	list;

	world = default_world();
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	list = intersect_world(world, ray);
	printf(GREY "intersect_world_test: ");
	if (list.total == 4 && check_double_values(list.head->t, 4.0)
		&& check_double_values(list.head->next->t, 4.5)
		&& check_double_values(list.head->next->next->t, 5.5)
		&& check_double_values(list.last->t, 6.0))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&(world.objects));
	free_intersection_list(&list);
	free(world.lights);
}

void	world_tests(void)
{
	printf(YELLOW "World tests: " END "\n");
	intersect_world_test();
	computations_tests();
	shade_hit_tests();
	transformation_tests();
}
