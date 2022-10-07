/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 16:15:27:06 by elraira-         ###   ########.fr       */
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
	sphere_tests();
	multiply_matrix_test();
	return (0);
}
