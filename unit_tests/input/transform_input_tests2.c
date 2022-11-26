/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_tests2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 14:55:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transform_orientation_test(char *str, t_vector expected, int s)
{
	int			status;
	t_vector	xyz;
	static int	n = 1;

	printf(GREY "transform_orientation_test %d: " END, n);
	status = OK;
	xyz = transform_orientation(str, &status);
	if (check_equal_vectors(xyz, expected) && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_double_test(char *str, double expected, int s)
{
	int			status;
	double		d;
	static int	n = 1;

	printf(GREY "transform_double_test %d: " END, n);
	status = OK;
	d = transform_double(str, &status);
	if (check_double_values(d, expected) && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_fov_test(char *str, int expected, int s)
{
	int			status;
	int			fov;
	static int	n = 1;

	printf(GREY "transform_fov_test %d: " END, n);
	status = OK;
	fov = transform_fov(str, &status);
	if (fov == expected && status == s)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	transform_input_tests_part2(void)
{
	transform_orientation_test("1.0,0.0,0.0", set_vector(1, 0, 0), OK);
	transform_orientation_test("0.0,1.0,0.0", set_vector(0, 1, 0), OK);
	transform_orientation_test("0.0,0.0,1.0", set_vector(0, 0, 1), OK);
	transform_orientation_test("0.0,0.0,0.0", set_vector(0, 0, 0), ERROR);
	transform_orientation_test("0.0,0.5,0.0", set_vector(0, 0.5, 0), ERROR);
	transform_orientation_test("50.0,0.0,20", set_vector(50.0, 0.0, 20), ERROR);
	transform_double_test("21.42", 21.42, OK);
	transform_double_test("20.888", 20.888, OK);
	transform_double_test("-20.888", -20.888, ERROR);
	transform_fov_test("0", 0, OK);
	transform_fov_test("180", 180, OK);
	transform_fov_test("-1", -1, ERROR);
	transform_fov_test("200", 200, ERROR);
	transform_fov_test("1800", 0, ERROR);
}
