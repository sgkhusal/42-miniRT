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

static t_matrix	matrix_a(void)
{
	t_matrix	a;

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
	return (a);
}

static t_matrix	matrix_b(void)
{
	t_matrix	b;

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
	return (b);
}

static void	check_result(t_matrix a, t_matrix d)
{
	int			i;
	int			j;

	i = 0;
	while (i < d.size)
	{
		j = 0;
		while (j < d.size)
		{
			if (check_double_values(d.matrix[i][j], a.matrix[i][j]) == false)
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

void	inverse_matrix_ultimate_test(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	t_matrix	b_inverse;
	t_matrix	d;

	printf(GREY "inverse_matrix_ultimate_test: " END);
	a = matrix_a();
	b = matrix_b();
	c = multiply_matrix(a, b);
	b_inverse = inverse_matrix(b);
	d = multiply_matrix(c, b_inverse);
	check_result(a, d);
	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
	free_matrix(d);
	free_matrix(b_inverse);
}
