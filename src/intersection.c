/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/13 12:16:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Allocates memory for a new t_intersection and initializes its values.
 * 
 * @param t intersection point distance
 * @param object object that the ray intersects
 * @return t_intersection* pointer to the new t_intersection
 */
t_intersection	*create_intersection(double t, t_object *object)
{
	t_intersection	*intersection;

	intersection = NULL;
	intersection = malloc(sizeof(t_intersection));
	if (!intersection)
		minirt_malloc_error("create_intersection");
	intersection->t = t;
	intersection->object = object;
	intersection->next = NULL;
	return (intersection);
}

/**
 * @brief adds a new intersection node to the list of intersections
 * 
 * @param node new intersection node
 * @param list list of intersections to add the new node to
 */
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

/**
 * @brief frees the memory allocated for the intersection list and its nodes.
 * 
 * @param list intersection list to be freed
 */
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

/**
 * @brief initializes the intersection list setting the head, last and total
 * values to NULL, NULL and 0 to avoid memory leaks and errors.
 * 
 * @param list intersection list
 */
void	init_intersection_list(t_intersection_list *list)
{
	list->head = NULL;
	list->last = NULL;
	list->total = 0;
}
