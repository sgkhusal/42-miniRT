/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:47:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/18 19:54:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_material_test(void)
{
	t_material		result;

	printf(GREY "set_material_test 1: " END);
	result = set_material();
	if (check_equal_vectors(set_vector(1, 1, 1), result.color)
		&& check_equal_vectors(set_vector(0.1, 0.1, 0.1), result.ambient)
		&& result.specular == 0.9
		&& result.diffuse == 0.9 && result.shininess == 200)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	material_tests(void)
{
	set_material_test();
}
