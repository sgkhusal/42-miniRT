/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:25:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 15:31:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	multiply_matrix_test(void)
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	res;
	t_matrix	expected;

	printf(GREY "multiply_matrix_test 1: ");
	m1 = create_matrix(4);
	m2 = create_matrix(4);
	expected = create_matrix(4);
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
	expected.matrix[0][0] = 20;
	expected.matrix[0][1] = 22;
	expected.matrix[0][2] = 50;
	expected.matrix[0][3] = 48;
	expected.matrix[1][0] = 44;
	expected.matrix[1][1] = 54;
	expected.matrix[1][2] = 114;
	expected.matrix[1][3] = 108;
	expected.matrix[2][0] = 40;
	expected.matrix[2][1] = 58;
	expected.matrix[2][2] = 110;
	expected.matrix[2][3] = 102;
	expected.matrix[3][0] = 16;
	expected.matrix[3][1] = 26;
	expected.matrix[3][2] = 46;
	expected.matrix[3][3] = 42;
	res = multiply_matrix(m1, m2);
	free_matrix(m1);
	free_matrix(m2);
	if (check_equal_matrices(expected, res))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(res);
	free_matrix(expected);
}

void	multiply_by_vector_test(void)
{
	t_matrix	m;
	t_vector	v;
	t_vector	expected;
	t_vector	res;

	printf(GREY "multiply_matrix_by_vector_test 1: ");
	m = create_matrix(4);
	v = set_vector(1, 2, 3);
	expected = set_vector(14, 22, 32);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 2;
	m.matrix[1][1] = 4;
	m.matrix[1][2] = 4;
	m.matrix[1][3] = 2;
	m.matrix[2][0] = 8;
	m.matrix[2][1] = 6;
	m.matrix[2][2] = 4;
	m.matrix[2][3] = 1;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	res = multiply_matrix_by_vector(m, v);
	free_matrix(m);
	if (res.x == expected.x && res.y == expected.y && res.z == expected.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	multiply_by_point_test(void)
{
	t_matrix	m;
	t_point		p;
	t_point		expected;
	t_point		res;

	printf(GREY "multiply_matrix_by_point_test 1: ");
	m = create_matrix(4);
	p = set_point(1, 2, 3);
	expected = set_point(18, 24, 33);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 2;
	m.matrix[1][1] = 4;
	m.matrix[1][2] = 4;
	m.matrix[1][3] = 2;
	m.matrix[2][0] = 8;
	m.matrix[2][1] = 6;
	m.matrix[2][2] = 4;
	m.matrix[2][3] = 1;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	res = multiply_matrix_by_point(m, p);
	free_matrix(m);
	if (res.x == expected.x && res.y == expected.y && res.z == expected.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	multiply_matrix_by_identity_test(void)
{
	t_matrix	m;
	t_matrix	identity;
	t_matrix	res;

	printf(GREY "multiply_matrix_by_identity_test 1: ");
	m = create_matrix(4);
	identity = identity_matrix(4);
	m.matrix[0][0] = 0;
	m.matrix[0][1] = 1;
	m.matrix[0][2] = 2;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 1;
	m.matrix[1][1] = 2;
	m.matrix[1][2] = 4;
	m.matrix[1][3] = 8;
	m.matrix[2][0] = 2;
	m.matrix[2][1] = 4;
	m.matrix[2][2] = 8;
	m.matrix[2][3] = 16;
	m.matrix[3][0] = 4;
	m.matrix[3][1] = 8;
	m.matrix[3][2] = 16;
	m.matrix[3][3] = 32;
	res = multiply_matrix(m, identity);
	free_matrix(identity);
	if (check_equal_matrices(m, res))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m);
}

void	all_matrix_multiply_tests(void)
{
	multiply_matrix_test();
	multiply_by_vector_test();
	multiply_by_point_test();
	multiply_matrix_by_identity_test();
}
