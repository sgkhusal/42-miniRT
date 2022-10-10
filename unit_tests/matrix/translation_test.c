/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:41:06 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 16:41:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	translation_test1(void)
{
	t_matrix	t;
	t_point		p;
	t_point		res;

	t = translation_matrix(5, -3, 2);
	p = set_point(-3, 4, 5);
	printf(GREY "translation_test 1: " END);
	res = multiply_matrix_by_point(t, p);
	if (res.x != 2 || res.y != 1 || res.z != 7 || res.w != 1)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
}

void	translation_test2(void)
{
	t_matrix	t;
	t_matrix	inverse;
	t_point		p;
	t_point		res;

	t = translation_matrix(5, -3, 2);
	inverse = inverse_matrix(t);
	p = set_point(-3, 4, 5);
	printf(GREY "translation_test 2: " END);
	res = multiply_matrix_by_point(inverse, p);
	if (res.x != -8 || res.y != 7 || res.z != 3 || res.w != 1)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
	free_matrix(inverse);
}

void	translation_test3(void)
{
	t_matrix	t;
	t_vector	v;
	t_vector	res;

	t = translation_matrix(5, -3, 2);
	v = set_vector(-3, 4, 5);
	printf(GREY "translation_test 3: " END);
	res = multiply_matrix_by_vector(t, v);
	if (res.x != -3 || res.y != 4 || res.z != 5 || res.w != 0)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
}

void	translation_test(void)
{
	translation_test1();
	translation_test2();
	translation_test3();
}
