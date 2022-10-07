/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:25:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/07 15:27:509 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "unit_tests.h"

void	multiply_matrix_test(void)
{
	t_matrix m1;
	t_matrix m2;
	t_matrix res;

	print (GREY "multiply_matrix_test 1: ");
	m1 = create_matrix(4);
	m2 = create_matrix(4);
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 2;
	m1.matrix[0][2] = 3;
	m1.matrix[0][3] = 4;
	m1.matrix[1][0] = 5;
	m1.matrix[1][1] = 6;
	m1.matrix[1][2] = 7;
	m1.matrix[1][3] = 8;
	m1.matrix[2][0] = 9;
	m1.matrix[2][1] = 8;
	m1.matrix[2][2] = 7;
	m1.matrix[2][3] = 6;
	m1.matrix[3][0] = 5;
	m1.matrix[3][1] = 4;
	m1.matrix[3][2] = 3;
	m1.matrix[3][3] = 2;

	m2.matrix[0][0] = -2;
	m2.matrix[0][1] = 1;
	m2.matrix[0][2] = 2;
	m2.matrix[0][3] = 3;
	m2.matrix[1][0] = 3;
	m2.matrix[1][1] = 2;
	m2.matrix[1][2] = 1;
	m2.matrix[1][3] = -1;
	m2.matrix[2][0] = 4;
	m2.matrix[2][1] = 3;
	m2.matrix[2][2] = 6;
	m2.matrix[2][3] = 5;
	m2.matrix[3][0] = 1;
	m2.matrix[3][1] = 2;
	m2.matrix[3][2] = 7;
	m2.matrix[3][3] = 8;

	res.matrix[0][0] = 20;
	res.matrix[0][1] = 22;
	res.matrix[0][2] = 50;
	res.matrix[0][3] = 48;
	res.matrix[1][0] = 44;
	res.matrix[1][1] = 54;
	res.matrix[1][2] = 114;
	res.matrix[1][3] = 108;
	res.matrix[2][0] = 40;
	res.matrix[2][1] = 58;
	res.matrix[2][2] = 110;
	res.matrix[2][3] = 102;
	res.matrix[3][0] = 16;
	res.matrix[3][1] = 26;
	res.matrix[3][2] = 46;
	res.matrix[3][3] = 42;

	if (check_equal_matrices(multiply_matrix(m1, m2), res))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}
