/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:25:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 20:37:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static t_matrix	matrix1(void)
{
	t_matrix	m1;

	m1 = create_matrix(4);
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 2;
	m1.matrix[0][2] = 3;
	m1.matrix[0][3] = 4;
	m1.matrix[1][0] = 5;
	m1.matrix[1][1] = 6;
	m1.matrix[1][2] = 7;
	m1.matrix[1][3] = 8;
	m1.matrix[2][0] = 9;
	m1.matrix[2][1] = 8;
	m1.matrix[2][2] = 7;
	m1.matrix[2][3] = 6;
	m1.matrix[3][0] = 5;
	m1.matrix[3][1] = 4;
	m1.matrix[3][2] = 3;
	m1.matrix[3][3] = 2;
	return (m1);
}

static t_matrix	matrix2(void)
{
	t_matrix	m2;

	m2 = create_matrix(4);
	m2.matrix[0][0] = -2;
	m2.matrix[0][1] = 1;
	m2.matrix[0][2] = 2;
	m2.matrix[0][3] = 3;
	m2.matrix[1][0] = 3;
	m2.matrix[1][1] = 2;
	m2.matrix[1][2] = 1;
	m2.matrix[1][3] = -1;
	m2.matrix[2][0] = 4;
	m2.matrix[2][1] = 3;
	m2.matrix[2][2] = 6;
	m2.matrix[2][3] = 5;
	m2.matrix[3][0] = 1;
	m2.matrix[3][1] = 2;
	m2.matrix[3][2] = 7;
	m2.matrix[3][3] = 8;
	return (m2);
}

static t_matrix	expected_matrix(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 20;
	m.matrix[0][1] = 22;
	m.matrix[0][2] = 50;
	m.matrix[0][3] = 48;
	m.matrix[1][0] = 44;
	m.matrix[1][1] = 54;
	m.matrix[1][2] = 114;
	m.matrix[1][3] = 108;
	m.matrix[2][0] = 40;
	m.matrix[2][1] = 58;
	m.matrix[2][2] = 110;
	m.matrix[2][3] = 102;
	m.matrix[3][0] = 16;
	m.matrix[3][1] = 26;
	m.matrix[3][2] = 46;
	m.matrix[3][3] = 42;
	return (m);
}

static void	multiply_matrix_test(void)
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	res;
	t_matrix	expected;

	printf(GREY "multiply_matrix_test 1: ");
	m1 = matrix1();
	m2 = matrix2();
	expected = expected_matrix();
	res = multiply_matrix(m1, m2);
	if (check_equal_matrices(expected, res))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m1);
	free_matrix(m2);
	free_matrix(res);
	free_matrix(expected);
}

void	all_matrix_multiply_tests(void)
{
	multiply_matrix_test();
	multiply_by_vector_test();
	multiply_by_point_test();
	multiply_matrix_by_identity_test();
}
