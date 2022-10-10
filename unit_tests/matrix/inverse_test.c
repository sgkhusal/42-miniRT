/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 16:35:14 by sguilher         ###   ########.fr       */
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
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			if (fabs(result.matrix[i][j] - expected.matrix[i][j]) > 0.00001)
			{
				printf(RED "KO" END "\n");
				n++;
				return ;
			}
			j++;
		}
		i++;
	}
	printf(GREEN "OK" END "\n");
	n++;
}

void	inverse_matrix_ultimate_test(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	t_matrix	b_inverse;
	t_matrix	d;
	int			i;
	int			j;

	printf(GREY "inverse_matrix_ultimate_test: " END);
	a = create_matrix(4);
	a.matrix[0][0] = 3;
	a.matrix[0][1] = -9;
	a.matrix[0][2] = 7;
	a.matrix[0][3] = 3;
	a.matrix[1][0] = 3;
	a.matrix[1][1] = -8;
	a.matrix[1][2] = 2;
	a.matrix[1][3] = -9;
	a.matrix[2][0] = -4;
	a.matrix[2][1] = 4;
	a.matrix[2][2] = 4;
	a.matrix[2][3] = 1;
	a.matrix[3][0] = -6;
	a.matrix[3][1] = 5;
	a.matrix[3][2] = -1;
	a.matrix[3][3] = 1;
	b = create_matrix(4);
	b.matrix[0][0] = 8;
	b.matrix[0][1] = 2;
	b.matrix[0][2] = 2;
	b.matrix[0][3] = 2;
	b.matrix[1][0] = 3;
	b.matrix[1][1] = -1;
	b.matrix[1][2] = 7;
	b.matrix[1][3] = 0;
	b.matrix[2][0] = 7;
	b.matrix[2][1] = 0;
	b.matrix[2][2] = 5;
	b.matrix[2][3] = 4;
	b.matrix[3][0] = 6;
	b.matrix[3][1] = -2;
	b.matrix[3][2] = 0;
	b.matrix[3][3] = 5;
	c = multiply_matrix(a, b);
	b_inverse = inverse_matrix(b);
	d = multiply_matrix(c, b_inverse);
	i = 0;
	while (i < d.size)
	{
		j = 0;
		while (j < d.size)
		{
			if (fabs(d.matrix[i][j] - a.matrix[i][j]) > 0.00001)
			{
				printf(RED "KO" END "\n");
				return ;
			}
			j++;
		}
		i++;
	}
	printf(GREEN "OK" END "\n");
}

void	inverse_matrix_test_cases(void)
{
	t_matrix	m1;
	t_matrix	expected;

	m1 = create_matrix(4);
	m1.matrix[0][0] = -5;
	m1.matrix[0][1] = 2;
	m1.matrix[0][2] = 6;
	m1.matrix[0][3] = -8;
	m1.matrix[1][0] = 1;
	m1.matrix[1][1] = -5;
	m1.matrix[1][2] = 1;
	m1.matrix[1][3] = 8;
	m1.matrix[2][0] = 7;
	m1.matrix[2][1] = 7;
	m1.matrix[2][2] = -6;
	m1.matrix[2][3] = -7;
	m1.matrix[3][0] = 1;
	m1.matrix[3][1] = -3;
	m1.matrix[3][2] = 7;
	m1.matrix[3][3] = 4;
	expected = create_matrix(4);
	expected.matrix[0][0] = 0.21805;
	expected.matrix[0][1] = 0.45113;
	expected.matrix[0][2] = 0.24060;
	expected.matrix[0][3] = -0.04511;
	expected.matrix[1][0] = -0.80827;
	expected.matrix[1][1] = -1.45677;
	expected.matrix[1][2] = -0.44361;
	expected.matrix[1][3] = 0.52068;
	expected.matrix[2][0] = -0.07895;
	expected.matrix[2][1] = -0.22368;
	expected.matrix[2][2] = -0.05263;
	expected.matrix[2][3] = 0.19737;
	expected.matrix[3][0] = -0.52256;
	expected.matrix[3][1] = -0.81391;
	expected.matrix[3][2] = -0.30075;
	expected.matrix[3][3] = 0.30639;
	inverse_matrix_test(m1, expected);
	m1.matrix[0][0] = 8;
	m1.matrix[0][1] = -5;
	m1.matrix[0][2] = 9;
	m1.matrix[0][3] = 2;
	m1.matrix[1][0] = 7;
	m1.matrix[1][1] = 5;
	m1.matrix[1][2] = 6;
	m1.matrix[1][3] = 1;
	m1.matrix[2][0] = -6;
	m1.matrix[2][1] = 0;
	m1.matrix[2][2] = 9;
	m1.matrix[2][3] = 6;
	m1.matrix[3][0] = -3;
	m1.matrix[3][1] = 0;
	m1.matrix[3][2] = -9;
	m1.matrix[3][3] = -4;
	expected.matrix[0][0] = -0.15385;
	expected.matrix[0][1] = -0.15385;
	expected.matrix[0][2] = -0.28205;
	expected.matrix[0][3] = -0.53846;
	expected.matrix[1][0] = -0.07692;
	expected.matrix[1][1] = 0.12308;
	expected.matrix[1][2] = 0.02564;
	expected.matrix[1][3] = 0.03077;
	expected.matrix[2][0] = 0.35897;
	expected.matrix[2][1] = 0.35897;
	expected.matrix[2][2] = 0.43590;
	expected.matrix[2][3] = 0.92308;
	expected.matrix[3][0] = -0.69231;
	expected.matrix[3][1] = -0.69231;
	expected.matrix[3][2] = -0.76923;
	expected.matrix[3][3] = -1.92308;
	inverse_matrix_test(m1, expected);
	m1.matrix[0][0] = 9;
	m1.matrix[0][1] = 3;
	m1.matrix[0][2] = 0;
	m1.matrix[0][3] = 9;
	m1.matrix[1][0] = -5;
	m1.matrix[1][1] = -2;
	m1.matrix[1][2] = -6;
	m1.matrix[1][3] = -3;
	m1.matrix[2][0] = -4;
	m1.matrix[2][1] = 9;
	m1.matrix[2][2] = 6;
	m1.matrix[2][3] = 4;
	m1.matrix[3][0] = -7;
	m1.matrix[3][1] = 6;
	m1.matrix[3][2] = 6;
	m1.matrix[3][3] = 2;
	expected.matrix[0][0] = -0.04074;
	expected.matrix[0][1] = -0.07778;
	expected.matrix[0][2] = 0.14444;
	expected.matrix[0][3] = -0.22222;
	expected.matrix[1][0] = -0.07778;
	expected.matrix[1][1] = 0.03333;
	expected.matrix[1][2] = 0.36667;
	expected.matrix[1][3] = -0.33333;
	expected.matrix[2][0] = -0.02901;
	expected.matrix[2][1] = -0.14630;
	expected.matrix[2][2] = -0.10926;
	expected.matrix[2][3] = 0.12963;
	expected.matrix[3][0] = 0.17778;
	expected.matrix[3][1] = 0.06667;
	expected.matrix[3][2] = -0.26667;
	expected.matrix[3][3] = 0.33333;
	inverse_matrix_test(m1, expected);
	free_matrix(m1);
	free_matrix(expected);
}
