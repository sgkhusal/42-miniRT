/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:20:28 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 22:47:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	transpose_test(t_matrix m1, t_matrix expected)
{
	t_matrix	transposed;

	printf(GREY "transpose_test 1: ");
	transposed = transposed_matrix(m1);
	if (check_equal_matrices(transposed, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m1);
	free_matrix(expected);
	free_matrix(transposed);
}

static t_matrix	m1(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 0;
	m.matrix[0][1] = 9;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 0;
	m.matrix[1][0] = 9;
	m.matrix[1][1] = 8;
	m.matrix[1][2] = 0;
	m.matrix[1][3] = 8;
	m.matrix[2][0] = 1;
	m.matrix[2][1] = 8;
	m.matrix[2][2] = 5;
	m.matrix[2][3] = 3;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 5;
	m.matrix[3][3] = 8;
	return (m);
}

static t_matrix	m2(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 0;
	m.matrix[0][1] = 9;
	m.matrix[0][2] = 1;
	m.matrix[0][3] = 0;
	m.matrix[1][0] = 9;
	m.matrix[1][1] = 8;
	m.matrix[1][2] = 8;
	m.matrix[1][3] = 0;
	m.matrix[2][0] = 3;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 5;
	m.matrix[2][3] = 5;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 8;
	m.matrix[3][2] = 3;
	m.matrix[3][3] = 8;
	return (m);
}

void	transpose_tests(void)
{
	transpose_test(m1(), m2());
}
