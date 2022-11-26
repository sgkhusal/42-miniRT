/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_tests1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 14:54:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transform_color_test(char *str, t_vector expected, int s)
{
	int			status;
	t_vector	color;
	static int	n = 1;

	printf(GREY "transform_color_test %d: " END, n);
	status = OK;
	color = transform_color(str, &status);
	if (check_equal_vectors(color, expected) && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_ratio_test(char *str, double expected, int s)
{
	int			status;
	double		ratio;
	static int	n = 1;

	printf(GREY "transform_ratio_test %d: " END, n);
	status = OK;
	ratio = transform_ratio(str, &status);
	if (check_double_values(ratio, expected) && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_coordinates_test(char *str, t_point expected, int s)
{
	int			status;
	t_point		xyz;
	static int	n = 1;

	printf(GREY "transform_coordinates_test %d: " END, n);
	status = OK;
	xyz = transform_coordinates(str, &status);
	if (check_equal_points(xyz, expected) && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_input_tests(void)
{
	char	input[20];

	printf(YELLOW "transform_input_tests:\n" END);
	transform_color_test("255,255,255", set_vector(1, 1, 1), OK);
	transform_color_test("100,50,150", set_vector(0.39216, 0.19608, 0.58824),
		OK);
	transform_color_test("0,0,0", set_vector(0, 0, 0), OK);
	transform_color_test("2555,255,255", set_vector(0, 0, 0), ERROR);
	transform_color_test("255,260,255", set_vector(1, 1.01961, 1), ERROR);
	transform_ratio_test(ft_memcpy(input, "0.0", 5), 0, OK);
	transform_ratio_test(ft_memcpy(input, "1.0", 5), 1, OK);
	transform_ratio_test(ft_memcpy(input, "0.55", 6), 0.55, OK);
	transform_ratio_test(ft_memcpy(input, "-0.2", 6), -0.2, ERROR);
	transform_ratio_test(ft_memcpy(input, "1.2", 5), 1.2, ERROR);
	transform_ratio_test(ft_memcpy(input, "2.837895792857", 16), 0, ERROR);
	transform_coordinates_test("50.0,0.0,20.6", set_point(50.0, 0.0, 20.6), OK);
	transform_coordinates_test("-40.0,50.0,0.0", set_point(-40.0, 50.0, 0.0),
		OK);
	transform_coordinates_test("0.0,0.0,0.0", set_point(0, 0, 0), OK);
	transform_coordinates_test("0,0,374824823848", set_point(0, 0, 0), ERROR);
	transform_input_tests_part2();
}
