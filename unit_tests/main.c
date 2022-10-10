/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 20:56:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(void)
{
	points_tests();
	vectors_tests();
	points_and_vectors_tests();
	//projectile_test();
	matrix_tests();
	ray_tests();
	//sphere_tests();
	return (0);
}
