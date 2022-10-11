/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_unit_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:43:34 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 16:07:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_vector_test(double x, double y, double z, int n)
{
	t_vector	vector;

	printf(GREY "set_vector_test %d: ", n);
	vector = set_vector(x, y, z);
	if (vector.x == x && vector.y == y && vector.z == z && vector.w == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
}

void	vector_length_test(double x, double y, double z, double expected)
{
	t_vector	vector;
	double		length;
	static int	n = 1;

	printf(GREY "vector_length_test %d: ", n);
	vector = set_vector(x, y, z);
	length = vector_length(vector);
	if (length == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	normalize_vector_test(double x, double y, double z, t_vector expected)
{
	t_vector	vector;
	t_vector	result;
	double		length;
	static int	n = 1;

	printf(GREY "normalize_vector_test %d: ", n);
	vector = set_vector(x, y, z);
	result = normalize_vector(vector);
	length = vector_length(result);
	if (check_double_values(length, 1)
		&& check_double_values(result.x, expected.x)
		&& check_double_values(result.y, expected.y)
		&& check_double_values(result.z, expected.z)
		&& result.w == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	vectors_tests(void)
{
	printf(YELLOW "Vectors tests: \n" END);
	set_vector_test(4.3, -4.2, 3.1, 1);
	set_vector_test(4, -4, 3, 1);
	vector_length_test(1, 0, 0, 1);
	vector_length_test(0, 1, 0, 1);
	vector_length_test(0, 0, 1, 1);
	vector_length_test(1, 2, 3, sqrt(14));
	vector_length_test(-1, -2, -3, sqrt(14));
	vector_length_test(0, 0, 0, 0);
	operations_vectors_test_cases();
	normalize_vector_test(4, 0, 0, set_vector(1, 0, 0));
	normalize_vector_test(1, 2, 3,
		set_vector(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14)));
	normalize_vector_test(3, 4, 5,
		set_vector(0.6 / sqrt(2), 0.8 / sqrt(2), 1 / sqrt(2)));
	scalar_product_test_cases();
	cross_product_test_cases();
}
