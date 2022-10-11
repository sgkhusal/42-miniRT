/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:28:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	inverse_matrix_test(t_matrix m, t_matrix expected)
{
	t_matrix	result;
	static int	n = 1;
	int			i;
	int			j;

	printf(GREY "inverse_matrix_test %d: " END, n);
	result = inverse_matrix(m);
	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
		{
			if (fabs(result.matrix[i][j] - expected.matrix[i][j]) > 0.00001)
			{
				printf(RED "KO" END "\n");
				n++;
				return ;
			}
		}
	}
	printf(GREEN "OK" END "\n");
	free_matrix(result);
	n++;
}

static t_matrix	m1(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = -5;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = 6;
	m.matrix[0][3] = -8;
	m.matrix[1][0] = 1;
	m.matrix[1][1] = -5;
	m.matrix[1][2] = 1;
	m.matrix[1][3] = 8;
	m.matrix[2][0] = 7;
	m.matrix[2][1] = 7;
	m.matrix[2][2] = -6;
	m.matrix[2][3] = -7;
	m.matrix[3][0] = 1;
	m.matrix[3][1] = -3;
	m.matrix[3][2] = 7;
	m.matrix[3][3] = 4;
	return (m);
}

static t_matrix	expected1(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 0.21805;
	m.matrix[0][1] = 0.45113;
	m.matrix[0][2] = 0.24060;
	m.matrix[0][3] = -0.04511;
	m.matrix[1][0] = -0.80827;
	m.matrix[1][1] = -1.45677;
	m.matrix[1][2] = -0.44361;
	m.matrix[1][3] = 0.52068;
	m.matrix[2][0] = -0.07895;
	m.matrix[2][1] = -0.22368;
	m.matrix[2][2] = -0.05263;
	m.matrix[2][3] = 0.19737;
	m.matrix[3][0] = -0.52256;
	m.matrix[3][1] = -0.81391;
	m.matrix[3][2] = -0.30075;
	m.matrix[3][3] = 0.30639;
	return (m);
}

static void	inverse_matrix_test_part1(void)
{
	t_matrix	m;
	t_matrix	expected;

	m = m1();
	expected = expected1();
	inverse_matrix_test(m, expected);
	free_matrix(m);
	free_matrix(expected);
}

void	inverse_matrix_tests(void)
{
	inverse_matrix_test_part1();
	inverse_matrix_test_part2();
}
