/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:26:32 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:25:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	submatrix_test(t_matrix m, int row, int column, t_matrix expected)
{
	t_matrix	submatrix;
	static int	n = 1;

	printf(GREY "submatrix_test %d: ", n);
	submatrix = get_submatrix(m, row, column);
	if (check_equal_matrices(submatrix, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(submatrix);
	n++;
	free_matrix(m);
	free_matrix(expected);
}

static t_matrix	m1(void)
{
	t_matrix	m;

	m = create_matrix(3);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 5;
	m.matrix[0][2] = 0;
	m.matrix[1][0] = -3;
	m.matrix[1][1] = 2;
	m.matrix[1][2] = 7;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = 6;
	m.matrix[2][2] = -3;
	return (m);
}

static t_matrix	m2(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -6;
	m.matrix[0][1] = 1;
	m.matrix[0][2] = 1;
	m.matrix[0][3] = 6;
	m.matrix[1][0] = -8;
	m.matrix[1][1] = 5;
	m.matrix[1][2] = 8;
	m.matrix[1][3] = 6;
	m.matrix[2][0] = -1;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 8;
	m.matrix[2][3] = 2;
	m.matrix[3][0] = -7;
	m.matrix[3][1] = 1;
	m.matrix[3][2] = -1;
	m.matrix[3][3] = 1;
	return (m);
}

void	submatrix_tests(void)
{
	t_matrix	m;
	t_matrix	expected1;
	t_matrix	expected2;

	m = m1();
	expected1 = create_matrix(2);
	expected1.matrix[0][0] = -3;
	expected1.matrix[0][1] = 2;
	expected1.matrix[1][0] = 0;
	expected1.matrix[1][1] = 6;
	submatrix_test(m, 0, 2, expected1);
	m = m2();
	expected2 = create_matrix(3);
	expected2.matrix[0][0] = -6;
	expected2.matrix[0][1] = 1;
	expected2.matrix[0][2] = 6;
	expected2.matrix[1][0] = -8;
	expected2.matrix[1][1] = 8;
	expected2.matrix[1][2] = 6;
	expected2.matrix[2][0] = -7;
	expected2.matrix[2][1] = -1;
	expected2.matrix[2][2] = 1;
	submatrix_test(m, 2, 1, expected2);
}
