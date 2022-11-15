/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:09:05 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/13 15:45:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

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
}

void	world_tests(void)
{
	printf(YELLOW "World tests: " END "\n");
	intersect_world_test();
	computations_tests();
	shade_hit_tests();
	transformation_tests();
}
