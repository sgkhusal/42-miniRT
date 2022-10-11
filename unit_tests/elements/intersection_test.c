/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:15:25 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 20:24:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	create_intersection_test(void)
{
	t_intersection	*intersection;

	printf(GREY "create_intersection_test 1: " END);
	intersection=  create_intersection(3.5, SPHERE);
	if (intersection->t == 3.5 && intersection->object == SPHERE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersection);
}

void	intersection_tests(void)
{
	printf(YELLOW "Intersection tests: " END "\n");
	create_intersection_test();
}
