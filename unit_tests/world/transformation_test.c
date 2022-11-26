/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:26:38 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:13:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	transformation_test(t_point from, t_vector orientation, t_vector up,
			t_matrix expected)
{
	t_matrix	result;
	static int	n = 1;

	printf(GREY "transformation_test %d: " END, n);
	result = view_transform(from, orientation, up);
	if (check_equal_matrices(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free_matrix(result);
	free_matrix(expected);
}

t_matrix	expected_matrix(void)
{
	t_matrix	expected;

	expected = identity_matrix(4);
	expected.matrix[0][0] = -0.50709;
	expected.matrix[0][1] = 0.50709;
	expected.matrix[0][2] = 0.67612;
	expected.matrix[0][3] = -2.36643;
	expected.matrix[1][0] = 0.76772;
	expected.matrix[1][1] = 0.60609;
	expected.matrix[1][2] = 0.12122;
	expected.matrix[1][3] = -2.82843;
	expected.matrix[2][0] = -0.35857;
	expected.matrix[2][1] = 0.59761;
	expected.matrix[2][2] = -0.71714;
	expected.matrix[2][3] = 0.00000;
	expected.matrix[3][0] = 0.00000;
	expected.matrix[3][1] = 0.00000;
	expected.matrix[3][2] = 0.00000;
	expected.matrix[3][3] = 1.00000;
	return (expected);
}

void	transformation_tests(void)
{
	t_point		from;
	t_vector	orientation;
	t_point		to;
	t_vector	up;
	t_matrix	expected;

	printf(YELLOW "transformation_tests: " END "\n");
	from = set_point(0, 0, 0);
	to = set_point(0, 0, -1);
	orientation = normalize_vector(subtract_points(to, from));
	up = set_vector(0, 1, 0);
	transformation_test(from, orientation, up, identity_matrix(4));
	to = set_point(0, 0, 1);
	orientation = normalize_vector(subtract_points(to, from));
	transformation_test(from, orientation, up, scaling_matrix(-1, 1, -1));
	from = set_point(0, 0, 8);
	to = set_point(0, 0, 0);
	orientation = normalize_vector(subtract_points(to, from));
	transformation_test(from, orientation, up, translation_matrix(0, 0, -8));
	from = set_point(1, 3, 2);
	to = set_point(4, -2, 8);
	orientation = normalize_vector(subtract_points(to, from));
	up = set_vector(1, 1, 0);
	transformation_test(from, orientation, up, expected_matrix());
}
