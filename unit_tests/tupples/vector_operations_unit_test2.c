/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_unit_test2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:00:27 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 18:40:14 by sguilher         ###   ########.fr       */
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

void	scalar_product_test_cases()
{
	t_vector	a;
	t_vector	b;
	double	expected;

	set_vector(&a, 3, -2, 5);
	set_vector(&b, -2, 3, 1);
	expected = -7;
	scalar_product_test(a, b, expected);
	set_vector(&a, 1, 2, 3);
	set_vector(&b, 2, 3, 4);
	expected = 20;
	scalar_product_test(a, b, expected);
}

void	cross_product_test(t_vector a, t_vector b, t_vector expected)
{
	t_vector	*result;
	static int	n = 1;

	printf(GREY "cross_product_test %d: ", n);
	result = cross_product(a, b);
	if (result->x == expected.x && result->y == expected.y
		&& result->z == expected.z)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(result);
	n++;
}

void	cross_product_test_cases()
{
	t_vector	a;
	t_vector	b;
	t_vector	expected;

	set_vector(&a, 1, 2, 3);
	set_vector(&b, 2, 3, 4);
	set_vector(&expected, -1, 2, -1);
	cross_product_test(a, b, expected);
	set_vector(&expected, 1, -2, 1);
	cross_product_test(b, a, expected);
}
