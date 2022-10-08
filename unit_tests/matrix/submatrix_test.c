/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:26:32 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 11:09:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unit_tests.h"

void	submatrix_test(t_matrix m, int row, int column, t_matrix expected)
{
	t_matrix sub;
	static int	n = 1;

	printf(GREY "submatrix test %d: ", n);
	sub = get_submatrix(m, row, column);
	if (check_equal_matrices(sub, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}


void	submatrix_test_cases()
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	expected1;
	t_matrix	expected2;

	m1 = create_matrix(3);
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 5;
	m1.matrix[0][2] = 0;
	m1.matrix[1][0] = -3;
	m1.matrix[1][1] = 2;
	m1.matrix[1][2] = 7;
	m1.matrix[2][0] = 0;
	m1.matrix[2][1] = 6;
	m1.matrix[2][2] = -3;

	expected1 = create_matrix(2);
	expected1.matrix[0][0] = -3;
	expected1.matrix[0][1] = 2;
	expected1.matrix[1][0] = 0;
	expected1.matrix[1][1] = 6;

	submatrix_test(m1, 0, 2, expected1);

	free_matrix(m1);
	free_matrix(expected1);

	m2 = create_matrix(4);
	m2.matrix[0][0] = -6;
	m2.matrix[0][1] = 1;
	m2.matrix[0][2] = 1;
	m2.matrix[0][3] = 6;
	m2.matrix[1][0] = -8;
	m2.matrix[1][1] = 5;
	m2.matrix[1][2] = 8;
	m2.matrix[1][3] = 6;
	m2.matrix[2][0] = -1;
	m2.matrix[2][1] = 0;
	m2.matrix[2][2] = 8;
	m2.matrix[2][3] = 2;
	m2.matrix[3][0] = -7;
	m2.matrix[3][1] = 1;
	m2.matrix[3][2] = -1;
	m2.matrix[3][3] = 1;

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

	submatrix_test(m2, 2, 1, expected2);

	free_matrix(m2);
	free_matrix(expected2);
}
