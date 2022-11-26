/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:26:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:19:07 by sguilher         ###   ########.fr       */
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
	t_comp		comp;
	t_material	material;
	t_vector	result;
	static int	n = 1;

	printf(GREY "lighting_test %d: " END, n);
	material = set_material();
	comp.point = set_point(0, 0, 0);
	comp.normalv = set_vector(0, 0, -1);
	comp.eyev = eye;
	result = lighting(material, light, comp, FALSE);
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

	printf(YELLOW "Lighting tests: " END "\n");
	normal_tests();
	reflection_tests();
	material_tests();
	set_light_test(set_point(0, 0, 0), set_vector(1, 1, 1));
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	lighting_test(light, eye, set_vector(1.9, 1.9, 1.9));
	eye = set_vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	light = set_point_light(set_point(0, 0, -10), set_vector(1, 1, 1));
	lighting_test(light, eye, set_vector(1.0, 1.0, 1.0));
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 10, -10), set_vector(1, 1, 1));
	lighting_test(light, eye, set_vector(0.7364, 0.7364, 0.7364));
	eye = set_vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	lighting_test(light, eye, set_vector(1.6364, 1.6364, 1.6364));
	eye = set_vector(0, 0, -1);
	light = set_point_light(set_point(0, 0, 10), set_vector(1, 1, 1));
	lighting_test(light, eye, set_vector(0.1, 0.1, 0.1));
}
