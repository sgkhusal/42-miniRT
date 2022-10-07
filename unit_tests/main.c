/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/07 17:46:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(void)
{
	points_tests();
	vectors_tests();
	points_and_vectors_tests();
	projectile_test();
	ray_tests();
	//sphere_tests();
	multiply_matrix_test();
	multiply_by_vector_test();
	multiply_by_point_test();
	multiply_matrix_by_identity_test();
	return (0);
}
