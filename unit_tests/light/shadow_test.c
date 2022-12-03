/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:13:33 by elraira-          #+#    #+#             */
/*   Updated: 2022/12/03 17:16:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	shadow_test1(void)
{
	t_comp		comp;
	t_light		light;
	t_vector	color;

	printf(GREY "shadow_test 1: " END);
	comp.eyev = set_vector(0, 0, -1);
	comp.normalv = set_vector(0, 0, -1);
	comp.point = set_point(0, 0, 0);
	light = set_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	color = lighting(set_material(), light, comp, TRUE);
	if (check_equal_vectors(color, set_vector(0, 0, 0)))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	shadow_test2(t_world world, t_point point, t_bool expected)
{
	static int	n = 2;
	t_bool		result;

	printf(GREY "shadow_test %d: " END, n);
	result = is_shadowed(world, point, *world.lights);
	if (result == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	shadow_test3(void)
{
	t_world			w;
	t_object		*s2;
	t_intersection	i;
	t_comp			comp;
	t_vector		result;

	printf(GREY "shadow_test 6: " END);
	w.objects = NULL;
	w.lights = NULL;
	w.lights = create_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	append_object(&w.objects, create_object(SPHERE, create_sphere()));
	s2 = create_object(SPHERE, create_sphere());
	set_transform(s2, translation_matrix(0, 0, 10));
	append_object(&w.objects, s2);
	i.t = 4;
	i.object = s2;
	comp = prepare_computations(set_ray(set_point(0, 0, 5),
				set_vector(0, 0, 1)), &i);
	result = get_total_color(w, comp);
	if (check_equal_vectors(result, set_vector(0.1, 0.1, 0.1)))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&w.objects);
	free(w.lights);
}

// Test for over_point
void	over_point_test(void)
{
	t_ray			ray;
	t_object		*sphere;
	t_intersection	*intersection;
	t_comp			comp;

	printf(GREY "over_point_test: " END);
	sphere = create_object(SPHERE, create_sphere());
	set_transform(sphere, translation_matrix(0, 0, 1));
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	intersection = create_intersection(5, sphere);
	comp = prepare_computations(ray, intersection);
	if (comp.over_point.z < -EPSILON / 2 && comp.point.z > comp.over_point.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&sphere);
	free(intersection);
}

void	shadow_tests(void)
{
	t_world		world;

	printf(YELLOW "Shadow tests: " END "\n");
	shadow_test1();
	world = default_world();
	shadow_test2(world, set_point(0, 10, 0), FALSE);
	shadow_test2(world, set_point(10, -10, 10), TRUE);
	shadow_test2(world, set_point(-20, 20, -20), FALSE);
	shadow_test2(world, set_point(-2, 2, -2), FALSE);
	shadow_test3();
	over_point_test();
	free_objects(&world.objects);
	free(world.lights);
}
