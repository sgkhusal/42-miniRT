/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:09:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 01:29:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	matrix_tests(void)
{
	printf(YELLOW "Matrix tests: \n" END);
	equality_tests();
	all_matrix_multiply_tests();
	identity_tests();
	transpose_tests();
	minor_tests();
	determinant_tests();
	submatrix_tests();
	cofactor_tests();
	inverse_matrix_tests();
	inverse_matrix_ultimate_test();
	translation_tests();
	scaling_tests();
	rotation_tests();
	shearing_tests();
	chaining_tests();
}
