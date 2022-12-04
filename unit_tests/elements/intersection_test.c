/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:15:25 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 21:11:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	create_intersection_test(void)
{
	t_intersection	*intersection;
	t_object		*object;

	object = create_object(SPHERE, create_sphere());
	printf(GREY "create_intersection_test 1: " END);
	intersection = create_intersection(3.5, object);
	if (intersection->t == 3.5 && intersection->object == object)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(intersection);
	free_objects(&object);
}

static void	get_hit_test(double t1, double t2, double expected)
{
	t_intersection_list	list;
	t_intersection		*hit;
	t_object			*object;
	static int			n = 1;

	object = create_object(SPHERE, create_sphere());
	printf(GREY "get_hit_test %d: " END, n);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(create_intersection(t1, object), &list);
	add_intersection_node(create_intersection(t2, object), &list);
	hit = get_hit_intersection(list);
	if (hit == NULL && expected == -1)
		printf(GREEN"OK" END "\n");
	else if (hit && hit->t == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free_intersection_list(&list);
	free_objects(&object);
}

static void	get_hit_test2(void)
{
	t_intersection_list	list;
	t_intersection		*hit;
	t_object			*object;

	object = create_object(SPHERE, create_sphere());
	printf(GREY "last_get_hit_test: " END);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(create_intersection(5, object), &list);
	add_intersection_node(create_intersection(7, object), &list);
	add_intersection_node(create_intersection(-3, object), &list);
	add_intersection_node(create_intersection(2, object), &list);
	hit = get_hit_intersection(list);
	if (hit && hit->t == 2.0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_intersection_list(&list);
	free_objects(&object);
}

static void	agregate_intersection_test(void)
{
	t_intersection_list	list;
	t_object			*object;

	object = create_object(SPHERE, create_sphere());
	printf(GREY "agregate_intersection_test 1: " END);
	list.head = NULL;
	list.last = NULL;
	add_intersection_node(create_intersection(1, object), &list);
	add_intersection_node(create_intersection(2, object), &list);
	if (list.head->t == 1 && list.head->next->t == 2 && list.last->t == 2
		&& list.total == 2 && list.head->object->type == SPHERE
		&& list.last->object->type == SPHERE)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_intersection_list(&list);
	free_objects(&object);
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
