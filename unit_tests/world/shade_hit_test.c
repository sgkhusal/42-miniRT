/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:38:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 11:53:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	shade_hit_test(t_world w, t_ray ray, t_intersection *xs,
			t_vector expected)
{
	t_comp		comps;
	t_vector	c;
	static int	n = 1;

	printf(GREY "shade_hit_test %d: " END, n);
	comps = prepare_computations(ray, xs);
	c = get_total_color(w, comps);
	if (check_equal_vectors(c, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free(xs);
}

void	color_at_test(t_world w, t_ray ray, t_vector expected)
{
	t_vector	result;
	static int	n = 1;

	printf(GREY "color_at_test %d: " END, n);
	result = color_at(w, ray);
	if (check_equal_vectors(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	color_at_tests(void)
{
	t_world			w;
	t_ray			ray;
	t_vector		expected;

	w = default_world();
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 1, 0));
	expected = set_vector(0, 0, 0);
	color_at_test(w, ray, expected);
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	expected = set_vector(0.38066, 0.47583, 0.2855);
	color_at_test(w, ray, expected);
	free_objects(&(w.objects));
	free(w.lights);
}

void	shade_hit_tests(void)
{
	t_world			w;
	t_ray			ray;
	t_intersection	*xs;
	t_vector		expected;

	printf(YELLOW "Shade hit tests: " END "\n");
	w = default_world();
	ray = set_ray(set_point(0, 0, -5), set_vector(0, 0, 1));
	xs = create_intersection(4, w.objects);
	expected = set_vector(0.38066, 0.47583, 0.2855);
	shade_hit_test(w, ray, xs, expected);
	*w.lights = set_point_light(set_point(0, 0.25, 0), set_vector(1, 1, 1));
	ray = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	xs = create_intersection(0.5, w.objects->next);
	expected = set_vector(0.90498, 0.90498, 0.90498);
	shade_hit_test(w, ray, xs, expected);
	free_objects(&(w.objects));
	free(w.lights);
	color_at_tests();
}
