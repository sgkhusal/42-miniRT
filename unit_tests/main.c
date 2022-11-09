/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(void)
{
	input_tests();
	ft_atod_tests();
	validate_input_tests();
	transform_input_tests();
	points_tests();
	vectors_tests();
	points_and_vectors_tests();
	matrix_tests();
	ray_tests();
	sphere_tests();
	intersection_tests();
	light_tests();
	cylinder_tests();
	world_tests();
	computations_tests();
	//sphere_render_test();
	cylinder_render_test();
	return (0);
}
