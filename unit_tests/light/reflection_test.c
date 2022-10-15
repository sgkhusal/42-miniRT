/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:42:10 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/15 10:52:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	reflection_test(t_vector incident, t_vector normal, t_vector expected)
{
	static int	n = 1;
	t_vector	result;

	printf(GREY "reflection_test %d: " END, n);
	result = reflect(incident, normal);
	if (check_equal_vectors(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	reflection_tests(void)
{
	t_vector	incident;
	t_vector	normal;
	t_vector	expected;

	incident =	set_vector(1, -1, 0);
	normal =	set_vector(0, 1, 0);
	expected =	set_vector(1, 1, 0);
	reflection_test(incident, normal, expected);
	incident =	set_vector(0, -1, 0);
	normal =	set_vector(sqrt(2) / 2, sqrt(2) / 2, 0);
	expected =	set_vector(1, 0, 0);
	reflection_test(incident, normal, expected);
}
