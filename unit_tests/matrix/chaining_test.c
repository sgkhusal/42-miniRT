/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaining_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:03 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 20:55:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	scenario1(void)
{
	t_point		p;
	t_point		result;
	t_matrix	rotation;
	t_matrix	scaling;
	t_matrix	translation;

	printf(GREY "chaining_scenario_1_test: " END);
	p = set_point(1, 0, 1);
	rotation = rotation_x_matrix(M_PI / 2);
	scaling = scaling_matrix(5, 5, 5);
	translation = translation_matrix(10, 5, 7);
	result = multiply_matrix_by_point(rotation, p);
	result = multiply_matrix_by_point(scaling, result);
	result = multiply_matrix_by_point(translation, result);
	if (check_double_values(result.x, 15)
		&& check_double_values(result.y, 0)
		&& check_double_values(result.z, 7)
		&& check_double_values(result.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(rotation);
	free_matrix(scaling);
	free_matrix(translation);
}

void	scenario2(void)
{
	t_point		point;
	t_point		result;
	t_matrix	rotation;
	t_matrix	scaling;
	t_matrix	translation;
	t_matrix	m1;
	t_matrix	m2;

	printf(GREY "chaining_scenario_2_test: " END);
	point = set_point(1, 0, 1);
	rotation = rotation_x_matrix(M_PI / 2);
	scaling = scaling_matrix(5, 5, 5);
	translation = translation_matrix(10, 5, 7);
	m1 = multiply_matrix(translation, scaling);
	m2 = multiply_matrix(m1, rotation);
	result = multiply_matrix_by_point(m2, point);
	if (check_double_values(result.x, 15)
		&& check_double_values(result.y, 0)
		&& check_double_values(result.z, 7)
		&& check_double_values(result.w, 1))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m1);
	free_matrix(m2);
	free_matrix(rotation);
	free_matrix(scaling);
	free_matrix(translation);
}

void	chaining_test(void)
{
	scenario1();
	scenario2();
}
