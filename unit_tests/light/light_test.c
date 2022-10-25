/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:26:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/17 15:13:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_light_test(t_point point, t_vector intesity)
{
	t_light		result;

	printf(GREY "set_light_test 1: " END);
	result = set_point_light(point, intesity);
	if (check_equal_points(point, result.position)
		&& check_equal_vectors(intesity, result.intensity))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	lighting_test(t_light light, t_vector eye, t_vector expected)
{
	t_point		point;
	t_material	material;
	t_vector	result;
	t_vector	normal;
	static int	n = 1;

	printf(GREY "lighting_test %d: " END, n);
	material = set_material();
	point = set_point(0, 0, 0);
	normal = set_vector(0, 0, -1);
	result = lighting(material, light, point, normal, eye);
	if (check_equal_vectors(expected, result))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	light_tests(void)
{
	t_light		light;
	t_vector	eye;
	t_vector	expected;

	printf(YELLOW "Lighting tests: " END "\n");
	normal_tests();
	reflection_tests();
	material_tests();
	set_light_test(set_point(0, 0, 0), set_vector(1, 1, 1));
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	expected = set_vector(1.9, 1.9, 1.9);
	lighting_test(light, eye, expected);
	eye = set_vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	light = set_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	expected = set_vector(1.0, 1.0, 1.0);
	lighting_test(light, eye, expected);
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 10, -10), set_vector(1, 1, 1));
	expected = set_vector(0.7364, 0.7364, 0.7364);
	lighting_test(light, eye, expected);
	eye = set_vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	expected = set_vector(1.6364, 1.6364, 1.6364);
	lighting_test(light, eye, expected);
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 0, 10), set_vector(1, 1, 1));
	expected = set_vector(0.1, 0.1, 0.1);
	lighting_test(light, eye, expected);
}
