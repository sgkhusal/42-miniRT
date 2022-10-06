/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_unit_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:43:34 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 20:30:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_vector_test(double x, double y, double z, int n)
{
	t_vector	*vector;

	printf(GREY "create_vector_test %d: ", n);
	vector = create_vector(x, y, z);
	if (vector->x == x && vector->y == y && vector->z == z && vector->w == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(vector);
}

void	vector_length_test(double x, double y, double z, double expected)
{
	t_vector	vector;
	double		length;
	static int	n = 1;

	printf(GREY "vector_length_test %d: ", n);
	set_vector(&vector, x, y, z);
	length = vector_length(vector);
	if (length == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	n++;
}

void	normalize_vector_test(double x, double y, double z,
	double expected_x, double expected_y, double expected_z)
{
	t_vector	vector;
	t_vector	expected;
	t_vector	*result;
	double		length;
	static int	n = 1;

	printf(GREY "normalize_vector_test %d: ", n);
	set_vector(&vector, x, y, z);
	set_vector(&expected, expected_x, expected_y, expected_z);
	result = normalize_vector(vector);
	length = vector_length(*result);
	if (length - 1 > -0.00001 && length - 1 < 0.00001
		&& result->x - expected.x > -0.00001 && result->x - expected.x < 0.00001
		&& result->y - expected.y > -0.00001 && result->y - expected.y < 0.00001
		&& result->z - expected.z > -0.00001 && result->z - expected.z < 0.00001
		&& result->w == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO\n" END);
	free(result);
	n++;
}

void	vectors_tests(void)
{
	printf(YELLOW "Vectors tests: \n" END);
	create_vector_test(4.3, -4.2, 3.1, 1);
	create_vector_test(4, -4, 3, 1);
	vector_length_test(1, 0, 0, 1);
	vector_length_test(0, 1, 0, 1);
	vector_length_test(0, 0, 1, 1);
	vector_length_test(1, 2, 3, sqrt(14));
	vector_length_test(-1, -2, -3, sqrt(14));
	vector_length_test(0, 0, 0, 0);
	operations_vectors_test_cases();
	normalize_vector_test(4, 0, 0, 1, 0, 0);
	normalize_vector_test(1, 2, 3, 1/sqrt(14), 2/sqrt(14), 3/sqrt(14));
	normalize_vector_test(3, 4, 5, 0.6/sqrt(2), 0.8/sqrt(2), 1/sqrt(2));
	scalar_product_test_cases();
	cross_product_test_cases();
}
