/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 22:24:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	identity_test(t_matrix identity, t_matrix expected)
{
	static int	n = 1;

	printf(GREY "identity_test %d: ", n);
	if (check_equal_matrices(identity, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(identity);
	free_matrix(expected);
	n++;
}

static t_matrix	identity_2(void)
{
	t_matrix	m;

	m = create_matrix(2);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 0;
	m.matrix[1][0] = 0;
	m.matrix[1][1] = 1;
	return (m);
}

static t_matrix	identity_3(void)
{
	t_matrix	m;

	m = create_matrix(3);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 0;
	m.matrix[0][2] = 0;
	m.matrix[1][0] = 0;
	m.matrix[1][1] = 1;
	m.matrix[1][2] = 0;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 1;
	return (m);
}

static t_matrix	identity_4(void)
{
	t_matrix	m;

	m = create_matrix(4);
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 0;
	m.matrix[0][2] = 0;
	m.matrix[0][3] = 0;
	m.matrix[1][0] = 0;
	m.matrix[1][1] = 1;
	m.matrix[1][2] = 0;
	m.matrix[1][3] = 0;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 1;
	m.matrix[2][3] = 0;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	return (m);
}

void	identity_tests(void)
{
	identity_test(identity_matrix(2), identity_2());
	identity_test(identity_matrix(3), identity_3());
	identity_test(identity_matrix(4), identity_4());
}
