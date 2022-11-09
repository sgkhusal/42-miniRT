/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:09:00 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 14:59:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_object(enum e_objects type, void *shape)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		minirt_malloc_error("create_object");
	obj->type = type;
	if (type == SPHERE)
		obj->shape.sphere = (t_sphere *)shape;
	else if (type == PLANE)
		obj->shape.plane = (t_plane *)shape;
	else if (type == CYLINDER)
		obj->shape.cylinder = (t_cylinder *)shape;
	obj->next = NULL;
	return (obj);
}

void	append_object(t_object **head, t_object *obj)
{
	t_object	*aux;

	if (*head == NULL)
	{
		*head = obj;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = obj;
}

void	free_objects(t_object **head)
{
	t_object	*aux;

	while (*head)
	{
		if ((*head)->type == SPHERE)
			free_sphere((*head)->shape.sphere);
		/* else if ((*head)->type == PLANE)
			free_plane((*head)->shape.plane); */
		else if ((*head)->type == CYLINDER)
			free_cylinder((*head)->shape.cylinder);
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}
