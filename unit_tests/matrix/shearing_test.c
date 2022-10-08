/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:17:06 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 16:38:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

t_shearing	set_shearing(double xy, double xz, double yx, double yz,
	double zx, double zy)
{
	t_shearing	s;

	s.x_y = xy;
	s.y_x = yx;
	s.x_z = xz;
	s.z_x = zx;
	s.y_z = yz;
	s.z_y = zy;
	return (s);
}

void	shearing_test(t_matrix s, t_point expected)
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

void	shearing_test_cases(void)
{
	t_matrix	matrix;
	t_shearing	shearing;

	shearing = set_shearing(1, 0, 0, 0, 0, 0);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(5, 3, 4));
	shearing = set_shearing(0, 1, 0, 0, 0, 0);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(6, 3, 4));
	shearing = set_shearing(0, 0, 1, 0, 0, 0);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(2, 5, 4));
	shearing = set_shearing(0, 0, 0, 1, 0, 0);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(2, 7, 4));
	shearing = set_shearing(0, 0, 0, 0, 1, 0);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(2, 3, 6));
	shearing = set_shearing(0, 0, 0, 0, 0, 1);
	matrix = shearing_matrix(shearing);
	shearing_test(matrix, set_point(2, 3, 7));
}

