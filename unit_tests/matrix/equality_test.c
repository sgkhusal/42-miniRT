/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	equality_test(t_matrix m1, t_matrix m2, bool expected)
{
	bool		res;
	static int	n = 1;

	printf(GREY "equality_test %d: ", n);
	if (check_equal_matrices(m1, m2) == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(m1);
	free_matrix(m2);
	n++;
}

static t_matrix	m1(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 5;
	m.matrix[1][1] = 6;
	m.matrix[1][2] = 7;
	m.matrix[1][3] = 8;
	m.matrix[2][0] = 9;
	m.matrix[2][1] = 8;
	m.matrix[2][2] = 7;
	m.matrix[2][3] = 6;
	m.matrix[3][0] = 5;
	m.matrix[3][1] = 4;
	m.matrix[3][2] = 3;
	m.matrix[3][3] = 2;
	return (m);
}

static t_matrix	m2(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 2;
	m.matrix[0][1] = 3;
	m.matrix[0][2] = 4;
	m.matrix[0][3] = 5;
	m.matrix[1][0] = 6;
	m.matrix[1][1] = 7;
	m.matrix[1][2] = 8;
	m.matrix[1][3] = 9;
	m.matrix[2][0] = 8;
	m.matrix[2][1] = 7;
	m.matrix[2][2] = 6;
	m.matrix[2][3] = 5;
	m.matrix[3][0] = 4;
	m.matrix[3][1] = 3;
	m.matrix[3][2] = 2;
	m.matrix[3][3] = 1;
	return (m);
}

void	equality_tests(void)
{
	equality_test(m1(), m1(), true);
	equality_test(m1(), m2(), false);
}
