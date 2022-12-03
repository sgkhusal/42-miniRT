/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:17:06 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 17:15:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static t_shearing	set_shearing(void)
{
	t_shearing	s;

	s.x_y = 1;
	s.x_z = 0;
	s.y_x = 0;
	s.y_z = 0;
	s.z_x = 0;
	s.z_y = 0;
	return (s);
}

static void	shearing_test(t_matrix s, t_point expected)
{
	t_point		p;
	t_point		res;
	static int	n = 1;

	printf(GREY "shearing_test %d: " END, n);
	p = set_point(2, 3, 4);
	res = multiply_matrix_by_point(s, p);
	if (check_double_values(res.x, expected.x)
		&& check_double_values(res.y, expected.y)
		&& check_double_values(res.z, expected.z)
		&& check_double_values(res.w, expected.w))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(s);
	n++;
}

void	shearing_tests(void)
{
	t_shearing	shearing;

	shearing = set_shearing();
	shearing_test(shearing_matrix(shearing), set_point(5, 3, 4));
	shearing.x_y = 0;
	shearing.x_z = 1;
	shearing_test(shearing_matrix(shearing), set_point(6, 3, 4));
	shearing.x_z = 0;
	shearing.y_x = 1;
	shearing_test(shearing_matrix(shearing), set_point(2, 5, 4));
	shearing.y_x = 0;
	shearing.y_z = 1;
	shearing_test(shearing_matrix(shearing), set_point(2, 7, 4));
	shearing.y_z = 0;
	shearing.z_x = 1;
	shearing_test(shearing_matrix(shearing), set_point(2, 3, 6));
	shearing.z_x = 0;
	shearing.z_y = 1;
	shearing_test(shearing_matrix(shearing), set_point(2, 3, 7));
}
