/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_test_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:25:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:16:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	determinant_test(t_matrix matrix, double expected)
{
	double		result;
	static int	n = 1;

	printf(GREY "determinant_test %d: ", n);
	result = get_determinant(matrix);
	if (fabs(expected - result) < 0.0001)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

static void	determinant_test_part1(void)
{
	t_matrix	m1;
	t_matrix	m2;

	m1 = create_matrix(2);
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 5;
	m1.matrix[1][0] = -3;
	m1.matrix[1][1] = 2;
	determinant_test(m1, 17);
	free_matrix(m1);
	m2 = create_matrix(3);
	m2.matrix[0][0] = 1;
	m2.matrix[0][1] = 2;
	m2.matrix[0][2] = 6;
	m2.matrix[1][0] = -5;
	m2.matrix[1][1] = 8;
	m2.matrix[1][2] = -4;
	m2.matrix[2][0] = 2;
	m2.matrix[2][1] = 6;
	m2.matrix[2][2] = 4;
	determinant_test(m2, -196);
	free_matrix(m2);
}

void	determinant_tests(void)
{
	determinant_test_part1();
	determinant_test_part2();
}
