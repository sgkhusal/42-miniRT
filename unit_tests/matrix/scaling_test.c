/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:00:17 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/08 15:10:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	scaling_test1(void)
{
	t_matrix	t;
	t_point		p;
	t_point		res;

	t = scaling_matrix(2, 3, 4);
	p = set_point(-4, 6, 8);
	printf(GREY "scaling_test 1: " END);
	res = multiply_matrix_by_point(t, p);
	if (res.x != -8 || res.y != 18 || res.z != 32 || res.w != 1)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
}

void	scaling_test2(void)
{
	t_matrix	t;
	t_vector	v;
	t_vector	res;

	t = scaling_matrix(2, 3, 4);
	v = set_vector(-4, 6, 8);
	printf(GREY "scaling_test 2: " END);
	res = multiply_matrix_by_vector(t, v);
	if (res.x != -8 || res.y != 18 || res.z != 32 || res.w != 0)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
}

void	scaling_test3(void)
{
	t_matrix	t;
	t_vector	v;
	t_vector	res;
	t_matrix	inv;

	t = scaling_matrix(2, 3, 4);
	inv = get_matrix_inverse(t);
	v = set_vector(-4, 6, 8);
	printf(GREY "scaling_test 3: " END);
	res = multiply_matrix_by_vector(inv, v);
	if (res.x != -2 || res.y != 2 || res.z != 2 || res.w != 0)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
	free_matrix(inv);
}

void	scaling_test4(void)
{
	t_matrix	t;
	t_point		p;
	t_point		res;

	t = scaling_matrix(-1, 1, 1);
	p = set_point(2, 3, 4);
	printf(GREY "scaling_test 4: " END);
	res = multiply_matrix_by_point(t, p);
	if (res.x != -2 || res.y != 3 || res.z != 4 || res.w != 1)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_matrix(t);
}

void	scaling_test(void)
{
	scaling_test1();
	scaling_test2();
	scaling_test3();
	scaling_test4();
}
