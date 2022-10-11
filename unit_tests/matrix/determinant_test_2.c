/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_test_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:04:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:10:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	invertible_test(t_matrix matrix, bool expected)
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

static t_matrix	m3(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -2;
	m.matrix[0][1] = -8;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 5;
	m.matrix[1][0] = -3;
	m.matrix[1][1] = 1;
	m.matrix[1][2] = 7;
	m.matrix[1][3] = 3;
	m.matrix[2][0] = 1;
	m.matrix[2][1] = 2;
	m.matrix[2][2] = -9;
	m.matrix[2][3] = 6;
	m.matrix[3][0] = -6;
	m.matrix[3][1] = 7;
	m.matrix[3][2] = 7;
	m.matrix[3][3] = -9;
	return (m);
}

static t_matrix	m4(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 6;
	m.matrix[0][1] = 4;
	m.matrix[0][2] = 4;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 5;
	m.matrix[1][1] = 5;
	m.matrix[1][2] = 7;
	m.matrix[1][3] = 6;
	m.matrix[2][0] = 4;
	m.matrix[2][1] = -9;
	m.matrix[2][2] = 3;
	m.matrix[2][3] = -7;
	m.matrix[3][0] = 9;
	m.matrix[3][1] = 1;
	m.matrix[3][2] = 7;
	m.matrix[3][3] = -6;
	return (m);
}

static t_matrix	m5(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -4;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = -2;
	m.matrix[0][3] = -3;
	m.matrix[1][0] = 9;
	m.matrix[1][1] = 6;
	m.matrix[1][2] = 2;
	m.matrix[1][3] = 6;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = -5;
	m.matrix[2][2] = 1;
	m.matrix[2][3] = -5;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 0;
	return (m);
}

void	determinant_test_part2(void)
{
	t_matrix	m;
	t_matrix	non_invertible;

	m = m3();
	determinant_test(m, -4071);
	free_matrix(m);
	m = m4();
	determinant_test(m, -2120);
	invertible_test(m, true);
	free_matrix(m);
	non_invertible = m5();
	determinant_test(non_invertible, 0);
	invertible_test(non_invertible, false);
	free_matrix(non_invertible);
}
