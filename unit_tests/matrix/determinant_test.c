/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraira-aira- <elralraira-a-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:25:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 10:35:58 by elralraira-a-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unit_tests.h"

void	determinant_test(t_matrix matrix, double expected)
{
	double	result;
	static int	n = 1;

	printf(GREY "determinant_test %d: ", n);
	result = get_matrix_determinant(matrix);
	if (fabs(expected - result) < 0.0001)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	determinant_test_cases()
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;

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
}

