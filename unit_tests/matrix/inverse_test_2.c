/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:28:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static t_matrix	m2(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 8;
	m.matrix[0][1] = -5;
	m.matrix[0][2] = 9;
	m.matrix[0][3] = 2;
	m.matrix[1][0] = 7;
	m.matrix[1][1] = 5;
	m.matrix[1][2] = 6;
	m.matrix[1][3] = 1;
	m.matrix[2][0] = -6;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 9;
	m.matrix[2][3] = 6;
	m.matrix[3][0] = -3;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = -9;
	m.matrix[3][3] = -4;
	return (m);
}

static t_matrix	expected2(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -0.15385;
	m.matrix[0][1] = -0.15385;
	m.matrix[0][2] = -0.28205;
	m.matrix[0][3] = -0.53846;
	m.matrix[1][0] = -0.07692;
	m.matrix[1][1] = 0.12308;
	m.matrix[1][2] = 0.02564;
	m.matrix[1][3] = 0.03077;
	m.matrix[2][0] = 0.35897;
	m.matrix[2][1] = 0.35897;
	m.matrix[2][2] = 0.43590;
	m.matrix[2][3] = 0.92308;
	m.matrix[3][0] = -0.69231;
	m.matrix[3][1] = -0.69231;
	m.matrix[3][2] = -0.76923;
	m.matrix[3][3] = -1.92308;
	return (m);
}

static t_matrix	m3(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 9;
	m.matrix[0][1] = 3;
	m.matrix[0][2] = 0;
	m.matrix[0][3] = 9;
	m.matrix[1][0] = -5;
	m.matrix[1][1] = -2;
	m.matrix[1][2] = -6;
	m.matrix[1][3] = -3;
	m.matrix[2][0] = -4;
	m.matrix[2][1] = 9;
	m.matrix[2][2] = 6;
	m.matrix[2][3] = 4;
	m.matrix[3][0] = -7;
	m.matrix[3][1] = 6;
	m.matrix[3][2] = 6;
	m.matrix[3][3] = 2;
	return (m);
}

static t_matrix	expected3(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -0.04074;
	m.matrix[0][1] = -0.07778;
	m.matrix[0][2] = 0.14444;
	m.matrix[0][3] = -0.22222;
	m.matrix[1][0] = -0.07778;
	m.matrix[1][1] = 0.03333;
	m.matrix[1][2] = 0.36667;
	m.matrix[1][3] = -0.33333;
	m.matrix[2][0] = -0.02901;
	m.matrix[2][1] = -0.14630;
	m.matrix[2][2] = -0.10926;
	m.matrix[2][3] = 0.12963;
	m.matrix[3][0] = 0.17778;
	m.matrix[3][1] = 0.06667;
	m.matrix[3][2] = -0.26667;
	m.matrix[3][3] = 0.33333;
	return (m);
}

void	inverse_matrix_test_part2(void)
{
	t_matrix	m;
	t_matrix	expected;

	m = m2();
	expected = expected2();
	inverse_matrix_test(m, expected);
	free_matrix(m);
	free_matrix(expected);
	m = m3();
	expected = expected3();
	inverse_matrix_test(m, expected);
	free_matrix(m);
	free_matrix(expected);
}
