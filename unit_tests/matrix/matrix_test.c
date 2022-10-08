/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:09:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 16:51:49 by sguilher         ###   ########.fr       */
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
	inverse_matrix_test_cases();
	inverse_matrix_ultimate_test();
	translation_test();
	scaling_test();
	rotation_test();
	shearing_test_cases();
	chaining_test();
}
