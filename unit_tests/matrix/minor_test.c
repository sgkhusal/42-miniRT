/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:36:51 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 22:47:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	minor_test(t_matrix m1, int row, int column, double expected)
{
	double		minor;
	static int	n = 1;
	
	printf(GREY "minor_test %d: ", n);
	minor = get_minor(m1, row, column);
	if (minor == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	minor_tests(void)
{
	t_matrix	m;

	m = create_matrix(3);
	m.matrix[0][0] = 3;
	m.matrix[0][1] = 5;
	m.matrix[0][2] = 0;
	m.matrix[1][0] = 2;
	m.matrix[1][1] = -1;
	m.matrix[1][2] = -7;
	m.matrix[2][0] = 6;
	m.matrix[2][1] = -1;
	m.matrix[2][2] = 5;
	minor_test(m, 1, 1, 15);
	minor_test(m, 1, 0, 25);
	free_matrix(m);
}
