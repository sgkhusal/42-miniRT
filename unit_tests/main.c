/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 15:44:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(int argc, char *argv[])
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
	if (argc == 1)
		return (0);
	if (strcmp(argv[1], "sp") == 0)
		sphere_render_test();
	else if (strcmp(argv[1], "cy") == 0)
		cylinder_render_test();
	return (0);
}
