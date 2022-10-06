/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_and_vectors_unit_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:43:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 00:18:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	add_point_and_vector_test(t_vector vector, t_point point,
	t_point expected)
{
	t_point		result;
	static int	n = 1;

	printf(GREY "add_point_and_vector_test %d: ", n);
	result = add_point_and_vector(point, vector);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z && result.w == expected.w)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	subtract_point_and_vector_test(t_vector vector, t_point point,
	t_point expected)
{
	t_point		result;
	static int	n = 1;

	printf(GREY "subract_point_and_vector_test %d: ", n);
	result = subtract_point_and_vector(point, vector);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z && result.w == expected.w)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	points_and_vectors_tests(void)
{
	t_vector	vector;
	t_point		point;
	t_point		expected;

	printf(YELLOW "Points and vectors tests: \n" END);
	point = create_point(3, -2, 5);
	vector = create_vector (-2, 3, 1);
	expected = create_point(1, 1, 6);
	add_point_and_vector_test(vector, point, expected);
	expected = create_point(5, -5, 4);
	subtract_point_and_vector_test(vector, point, expected);
	point = create_point(3, 2, 1);
	vector = create_vector (5, 6, 7);
	expected = create_point(8, 8, 8);
	add_point_and_vector_test(vector, point, expected);
	expected = create_point(-2, -4, -6);
	subtract_point_and_vector_test(vector, point, expected);
}
