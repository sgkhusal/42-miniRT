/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_unit_test2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:00:27 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 00:19:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	scalar_product_test(t_vector a, t_vector b, double expected)
{
	double		result;
	static int	n = 1;

	printf(GREY "scalar_product_test %d: ", n);
	result = scalar_product(a, b);
	if (result == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	scalar_product_test_cases(void)
{
	t_vector	a;
	t_vector	b;
	double		expected;

	a = create_vector(3, -2, 5);
	b = create_vector(-2, 3, 1);
	expected = -7;
	scalar_product_test(a, b, expected);
	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	expected = 20;
	scalar_product_test(a, b, expected);
}

void	cross_product_test(t_vector a, t_vector b, t_vector expected)
{
	t_vector	result;
	static int	n = 1;

	printf(GREY "cross_product_test %d: ", n);
	result = cross_product(a, b);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	cross_product_test_cases(void)
{
	t_vector	a;
	t_vector	b;
	t_vector	expected;

	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	expected = create_vector(-1, 2, -1);
	cross_product_test(a, b, expected);
	expected = create_vector(1, -2, 1);
	cross_product_test(b, a, expected);
}
