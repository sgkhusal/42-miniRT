/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:25:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 16:32:57 by sguilher         ###   ########.fr       */
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

void	invertible_test(t_matrix matrix, bool expected)
{
	bool		result;
	static int	n = 1;

	printf(GREY "invertible_test %d: ", n);
	result = get_determinant(matrix);
	if (expected == result)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	determinant_test_cases(void)
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;
	t_matrix	m4;
	t_matrix	non_invertible;

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
	m3 = create_matrix(4);
	m3.matrix[0][0] = -2;
	m3.matrix[0][1] = -8;
	m3.matrix[0][2] = 3;
	m3.matrix[0][3] = 5;
	m3.matrix[1][0] = -3;
	m3.matrix[1][1] = 1;
	m3.matrix[1][2] = 7;
	m3.matrix[1][3] = 3;
	m3.matrix[2][0] = 1;
	m3.matrix[2][1] = 2;
	m3.matrix[2][2] = -9;
	m3.matrix[2][3] = 6;
	m3.matrix[3][0] = -6;
	m3.matrix[3][1] = 7;
	m3.matrix[3][2] = 7;
	m3.matrix[3][3] = -9;
	determinant_test(m3, -4071);
	free_matrix(m3);
	m4 = create_matrix(4);
	m4.matrix[0][0] = 6;
	m4.matrix[0][1] = 4;
	m4.matrix[0][2] = 4;
	m4.matrix[0][3] = 4;
	m4.matrix[1][0] = 5;
	m4.matrix[1][1] = 5;
	m4.matrix[1][2] = 7;
	m4.matrix[1][3] = 6;
	m4.matrix[2][0] = 4;
	m4.matrix[2][1] = -9;
	m4.matrix[2][2] = 3;
	m4.matrix[2][3] = -7;
	m4.matrix[3][0] = 9;
	m4.matrix[3][1] = 1;
	m4.matrix[3][2] = 7;
	m4.matrix[3][3] = -6;
	determinant_test(m4, -2120);
	invertible_test(m4, true);
	free_matrix(m4);
	non_invertible = create_matrix(4);
	non_invertible.matrix[0][0] = -4;
	non_invertible.matrix[0][1] = 2;
	non_invertible.matrix[0][2] = -2;
	non_invertible.matrix[0][3] = -3;
	non_invertible.matrix[1][0] = 9;
	non_invertible.matrix[1][1] = 6;
	non_invertible.matrix[1][2] = 2;
	non_invertible.matrix[1][3] = 6;
	non_invertible.matrix[2][0] = 0;
	non_invertible.matrix[2][1] = -5;
	non_invertible.matrix[2][2] = 1;
	non_invertible.matrix[2][3] = -5;
	non_invertible.matrix[3][0] = 0;
	non_invertible.matrix[3][1] = 0;
	non_invertible.matrix[3][2] = 0;
	non_invertible.matrix[3][3] = 0;
	determinant_test(non_invertible, 0);
	invertible_test(non_invertible, false);
	free_matrix(non_invertible);
}
