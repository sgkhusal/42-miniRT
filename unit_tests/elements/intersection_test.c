/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:15:25 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/14 20:54:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	create_intersection_test(void)
{
	t_intersection	*intersection;

	printf(GREY "create_intersection_test 1: " END);
	intersection = create_intersection(3.5, SPHERE);
	if (intersection->t == 3.5 && intersection->object == SPHERE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersection);
}

static void	get_hit_test(double t1, double t2, double expected)
{
	t_intersection_list	list;
	t_intersection		*inter1;
	t_intersection		*inter2;
	static int			n = 1;
	t_intersection		*hit;

	printf(GREY "get_hit_test %d: " END, n);
	inter1 = create_intersection(t1, SPHERE);
	inter2 = create_intersection(t2, SPHERE);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(inter1, &list);
	add_intersection_node(inter2, &list);
	hit = get_hit_intersection(list);
	if (hit == NULL && expected == -1)
		printf(GREEN "OK" END "\n");
	else if (hit && hit->t == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free(inter1);
	free(inter2);
}

static void	get_hit_test2(void)
{
	t_intersection_list	list;
	t_intersection		*inter1;
	t_intersection		*inter2;
	t_intersection		*inter3;
	t_intersection		*inter4;
	t_intersection		*hit;

	printf(GREY "last_get_hit_test: " END);
	inter1 = create_intersection(5, SPHERE);
	inter2 = create_intersection(7, SPHERE);
	inter3 = create_intersection(-3, SPHERE);
	inter4 = create_intersection(2, SPHERE);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(inter1, &list);
	add_intersection_node(inter2, &list);
	add_intersection_node(inter3, &list);
	add_intersection_node(inter4, &list);
	hit = get_hit_intersection(list);
	if (hit && hit->t == 2.0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(inter1);
	free(inter2);
	free(inter3);
	free(inter4);
}

static void	agregate_intersection_test(void)
{
	t_intersection_list	list;
	t_intersection		*intersection1;
	t_intersection		*intersection2;

	printf(GREY "agregate_intersection_test 1: " END);
	intersection1 = create_intersection(1, SPHERE);
	intersection2 = create_intersection(2, SPHERE);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(intersection1, &list);
	add_intersection_node(intersection2, &list);
	if (list.head->t == 1 && list.head->next->t == 2 && list.last->t == 2
		&& list.total == 2 && list.head->object == SPHERE
		&& list.last->object == SPHERE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersection1);
	free(intersection2);
}

void	intersection_tests(void)
{
	printf(YELLOW "Intersection tests: " END "\n");
	create_intersection_test();
	agregate_intersection_test();
	get_hit_test(1, 2, 1);
	get_hit_test(-1, 1, 1);
	get_hit_test(-2, -1, -1);
	get_hit_test2();
}
