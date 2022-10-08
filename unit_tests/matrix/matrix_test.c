/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:29:03 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 11:14:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	matrix_tests(void)
{
	printf(YELLOW "Matrix tests: \n" END);
	all_matrix_multiply_tests();
	determinant_test_cases();
	submatrix_test_cases();
	cofactor_test_cases();
}
