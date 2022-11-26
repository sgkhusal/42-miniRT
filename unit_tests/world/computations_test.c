/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:25:27 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:14:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	computations_test1(t_ray ray, t_intersection *intersect)
{
	t_comp	comp;

	printf(GREY "computation_test 1: ");
	comp = prepare_computations(ray, intersect);
	if (check_double_values(comp.xs->t, 4.0)
		&& check_equal_points(comp.point, set_point(0, 0, -1))
		&& check_equal_vectors(comp.eyev, set_vector(0, 0, -1))
		&& check_equal_vectors(comp.normalv, set_vector(0, 0, -1))
		&& &(comp.xs->object) == &(intersect->object)
		&& comp.inside == FALSE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersect);
}

void	computations_test2(t_ray ray, t_intersection *intersect)
{
	t_comp	comp;

	printf(GREY "computation_test 2: ");
	comp = prepare_computations(ray, intersect);
	if (check_equal_points(comp.point, set_point(0, 0, 1))
		&& check_equal_vectors(comp.eyev, set_vector(0, 0, -1))
		&& check_equal_vectors(comp.normalv, set_vector(0, 0, -1))
		&& comp.inside == TRUE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersect);
}

void	computations_tests(void)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = create_sphere();
	object = create_object(SPHERE, sphere);
	printf(YELLOW "Computations tests:\n" END);
	computations_test1(set_ray(set_point(0, 0, -5), set_vector(0, 0, 1)),
		create_intersection(4, object));
	computations_test2(set_ray(set_point(0, 0, 0), set_vector(0, 0, 1)),
		create_intersection(1, object));
	free_objects(&object);
}
