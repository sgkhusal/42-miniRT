/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:21:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 20:51:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	rotation_x_test1(void)
{
	t_matrix	rotation;
	t_point		p;
	t_point		res;

	printf(GREY "rotation_x_test 1: " END);
	rotation = rotation_x_matrix(M_PI / 4);
	p = set_point(0, 1, 0);
	res = multiply_matrix_by_point(rotation, p);
	if (check_double_values(res.x, 0) && check_double_values(res.y, sqrt(2) / 2)
		&& check_double_values(res.z, sqrt(2) / 2)
		&& check_double_values(res.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
	printf(GREY "rotation_x_test 2: " END);
	rotation = rotation_x_matrix(M_PI / 2);
	res = multiply_matrix_by_point(rotation, p);
	if (check_double_values(res.x, 0) && check_double_values(res.y, 0)
		&& check_double_values(res.z, 1) && check_double_values(res.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
}

static void	rotation_x_test2(void)
{
	t_matrix	rotation;
	t_matrix	inverse;
	t_point		p;
	t_point		res;

	printf(GREY "rotation_x_test 3: " END);
	p = set_point(0, 1, 0);
	rotation = rotation_x_matrix(M_PI / 4);
	inverse = inverse_matrix(rotation);
	res = multiply_matrix_by_point(inverse, p);
	if (check_double_values(res.x, 0)
		&& check_double_values(res.y, sqrt(2) / 2)
		&& check_double_values(res.z, (-1) * sqrt(2) / 2)
		&& check_double_values(res.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
	free_matrix(inverse);
}

static void	rotation_y_test(void)
{
	t_point		point;
	t_matrix	rotation;

	printf(GREY "rotation_y_test 1: " END);
	point = set_point(0, 0, 1);
	rotation = rotation_y_matrix(M_PI / 4);
	point = multiply_matrix_by_point(rotation, point);
	if (check_double_values(point.x, sqrt(2) / 2)
		&& check_double_values(point.y, 0)
		&& check_double_values(point.z, sqrt(2) / 2)
		&& check_double_values(point.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	printf(GREY "rotation_y_test 2: " END);
	free_matrix(rotation);
	point = set_point(0, 0, 1);
	rotation = rotation_y_matrix(M_PI / 2);
	point = multiply_matrix_by_point(rotation, point);
	if (check_double_values(point.x, 1) && check_double_values(point.y, 0)
		&& check_double_values(point.z, 0) && check_double_values(point.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
}

static void	rotation_z_test(void)
{
	t_point		point;
	t_matrix	rotation;

	printf(GREY "rotation_z_test 1: " END);
	point = set_point(0, 1, 0);
	rotation = rotation_z_matrix(M_PI / 4);
	point = multiply_matrix_by_point(rotation, point);
	if (check_double_values(point.x, -sqrt(2) / 2)
		&& check_double_values(point.y, sqrt(2) / 2)
		&& check_double_values(point.z, 0)
		&& check_double_values(point.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
	printf(GREY "rotation_z_test 2: " END);
	point = set_point(0, 1, 0);
	rotation = rotation_z_matrix(M_PI / 2);
	point = multiply_matrix_by_point(rotation, point);
	if (check_double_values(point.x, -1) && check_double_values(point.y, 0)
		&& check_double_values(point.z, 0) && check_double_values(point.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
}

void	rotation_tests(void)
{
	rotation_x_test1();
	rotation_x_test2();
	rotation_y_test();
	rotation_z_test();
}
