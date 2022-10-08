/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:29:03 by sguilher          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/08 15:43:01 by sguilher         ###   ########.fr       */
=======
/*   Updated: 2022/10/08 12:34:56 by sguilher         ###   ########.fr       */
>>>>>>> 63f8f74273a9c4b12eece1c88b57246ef8475303
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
<<<<<<< HEAD
	translation_test();
	scaling_test();
	rotation_test();
=======
>>>>>>> 63f8f74273a9c4b12eece1c88b57246ef8475303
}
