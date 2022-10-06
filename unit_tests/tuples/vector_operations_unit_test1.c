/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_unit_test1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 00:17:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	add_vectors_test(t_vector a, t_vector b, t_vector expected)
{
	t_vector	result;
	static int	n = 1;

	printf(GREY "add_vectors_test %d: ", n);
	result = add_vectors(a, b);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z && result.w == expected.w)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	subtract_vectors_test(t_vector a, t_vector b, t_vector expected)
{
	t_vector	result;
	static int	n = 1;

	printf(GREY "subtract_vectors_test %d: ", n);
	result = subtract_vectors(a, b);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z && result.w == expected.w)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	multiply_vector_by_scalar_test(t_vector vector, double scalar,
	t_vector expected)
{
	t_vector	result;
	static int	n = 1;

	printf(GREY "multiply_vector_by_scalar_test %d: ", n);
	result = multiply_vector_by_scalar(vector, scalar);
	if (result.x == expected.x && result.y == expected.y
		&& result.z == expected.z && result.w == expected.w)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	operations_vectors_test_cases(void)
{
	t_vector	a;
	t_vector	b;
	t_vector	expected;

	a = create_vector(3, -2, 5);
	b = create_vector(-2, 3, 1);
	expected = create_vector(1, 1, 6);
	add_vectors_test(a, b, expected);
	expected = create_vector(5, -5, 4);
	subtract_vectors_test(a, b, expected);
	a = create_vector(3, 2, 1);
	b = create_vector(5, 6, 7);
	expected = create_vector(8, 8, 8);
	add_vectors_test(a, b, expected);
	expected = create_vector(-2, -4, -6);
	subtract_vectors_test(a, b, expected);
	a = create_vector(1, -2, 3);
	expected = create_vector(3.5, -7, 10.5);
	multiply_vector_by_scalar_test(a, 3.5, expected);
	a = create_vector(1, -2, 3);
	expected = create_vector(0.5, -1, 1.5);
	multiply_vector_by_scalar_test(a, 0.5, expected);
}
