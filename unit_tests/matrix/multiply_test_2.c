/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_test_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:25:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/11 00:46:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static t_matrix	m1(void)
{
	t_matrix	m;

	m = create_matrix(4);
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
	return (m);
}

void	multiply_by_vector_test(void)
{
	t_matrix	m;
	t_vector	v;
	t_vector	expected;
	t_vector	res;

	printf(GREY "multiply_matrix_by_vector_test 1: ");
	m = m1();
	v = set_vector(1, 2, 3);
	expected = set_vector(14, 22, 32);
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
	m = m1();
	p = set_point(1, 2, 3);
	expected = set_point(18, 24, 33);
	res = multiply_matrix_by_point(m, p);
	free_matrix(m);
	if (res.x == expected.x && res.y == expected.y && res.z == expected.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

static t_matrix	m2(void)
{
	t_matrix	m;

	m = create_matrix(4);
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
	return (m);
}

void	multiply_matrix_by_identity_test(void)
{
	t_matrix	m;
	t_matrix	identity;
	t_matrix	res;

	printf(GREY "multiply_matrix_by_identity_test 1: ");
	identity = identity_matrix(4);
	m = m2();
	res = multiply_matrix(m, identity);
	free_matrix(identity);
	if (check_equal_matrices(m, res))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m);
	free_matrix(res);
}
