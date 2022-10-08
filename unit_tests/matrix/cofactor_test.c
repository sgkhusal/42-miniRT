/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:26:49 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 11:20:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unit_tests.h"

void	cofactor_test(t_matrix m, int row, int column, double expected)
{
	double	result;
	static int	n = 1;

	printf(GREY "cofactor_test %d: ", n);
	result = get_matrix_cofactor(m, row, column);
	if (fabs(expected - result) < 0.0001)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	cofactor_test_cases(void)
{
	t_matrix	m1;

	m1 = create_matrix(3);
	m1.matrix[0][0] = 3;
	m1.matrix[0][1] = 5;
	m1.matrix[0][2] = 0;
	m1.matrix[1][0] = 2;
	m1.matrix[1][1] = -1;
	m1.matrix[1][2] = -7;
	m1.matrix[2][0] = 6;
	m1.matrix[2][1] = -1;
	m1.matrix[2][2] = 5;
	cofactor_test(m1, 0, 0, -12);
	cofactor_test(m1, 1, 0, -25);
	free_matrix(m1);
}
