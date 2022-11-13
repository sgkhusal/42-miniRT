/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/29 15:20:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_swap(t_intersection **a)
{
	t_intersection	*b;
	double			tmp;
	t_object		*object_tmp;

	tmp = (*a)->t;
	object_tmp = (*a)->object;
	b = (*a)->next;
	(*a)->t = b->t;
	(*a)->object = b->object;
	b->t = tmp;
	b->object = object_tmp;
}

int	is_intersect_sorted(t_intersection_list *lst)
{
	t_intersection	*aux1;
	t_intersection	*aux2;

	aux1 = lst->head;
	aux2 = aux1->next;
	while (aux2)
	{
		if (aux1->t > aux2->t)
			return (FALSE);
		aux1 = aux2;
		aux2 = aux2->next;
	}
	return (TRUE);
}

void	intersect_sort(t_intersection **head)
{
	t_intersection	*aux1;
	t_intersection	*aux2;

	if (*head == NULL)
		return ;
	aux1 = *head;
	while (aux1)
	{
		aux2 = aux1->next;
		while (aux2)
		{
			if (aux1->t > aux2->t)
				ft_swap(&aux1);
			aux2 = aux2->next;
		}
		aux1 = (aux1->next);
	}
}
