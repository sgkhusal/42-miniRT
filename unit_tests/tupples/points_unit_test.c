/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_unit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:55:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 16:56:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_point_test(double x, double y, double z, int n)
{
	t_point	*point;

	printf(GREY "create_point_test %d: ", n);
	point = create_point(x, y, z);
	if (point->x == x && point->y == y && point->z == z && point->w == 1)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(point);
}

void	subtract_points_test(t_point a, t_point b, t_vector expected)
{
	t_vector	*result;
	static int	n = 1;

	printf(GREY "subtract_points_test %d: ", n);
	result = subtract_points(a, b);
	if (result->x == expected.x && result->y == expected.y
		&& result->z == expected.z && result->w == expected.w)
			printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(result);
	n++;
}

void	operations_points_test_cases()
{
	t_point	a;
	t_point	b;
	t_vector	expected;

	set_point(&a, 3, -2, 5);
	set_point(&b, -2, 3, 1);
	set_vector(&expected, 5, -5, 4);
	subtract_points_test(a, b, expected);
	set_point(&a, 3, 2, 1);
	set_point(&b, 5, 6, 7);
	set_vector(&expected, -2, -4, -6);
	subtract_points_test(a, b, expected);
}

void	points_tests()
{
	printf(YELLOW "Points tests: \n" END);
	create_point_test(4, -4, 3, 1);
	create_point_test(4.3, -4.2, 3.1, 2);
	operations_points_test_cases();
}
