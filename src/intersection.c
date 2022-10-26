/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/26 17:29:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*create_intersection(double t, int object)
{
	t_intersection	*intersection;

	intersection = malloc(sizeof(t_intersection));
	if (!intersection)
		minirt_malloc_error("create_intersection");
	intersection->t = t;
	intersection->object = object;
	intersection->next = NULL;
	return (intersection);
}

void	add_intersection_node(t_intersection *node, t_intersection_list *list)
{
	if (!node)
		return ;
	if (!list->head)
	{
		list->head = node;
		list->last = node;
		list->total = 1;
		return ;
	}
	list->last->next = node;
	list->last = node;
	list->total++;
}

void	free_intersection_list(t_intersection_list *list)
{
	t_intersection	*node;
	t_intersection	*next;

	node = list->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	list->head = NULL;
	list->last = NULL;
	list->total = 0;
}

void	init_intersection_list(t_intersection_list *list)
{
	list->head = NULL;
	list->last = NULL;
	list->total = 0;
}
