/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:09:00 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 11:43:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will create a new object of a given type and allocate
 * memory for it. It will also initialize the common attributes of all objects.
 *
 * @param type type of the object to be created
 * @param shape void pointer to the shape of the object that will be casted to
 * the correct type
 * @return t_object* a pointer to the new object
 */
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
	obj->transform = identity_matrix(4);
	obj->inverse = identity_matrix(4);
	obj->transpose_inverse = identity_matrix(4);
	obj->material = set_material();
	obj->next = NULL;
	return (obj);
}

/**
 * @brief This function will append a new object to the end of the list of
 * objects in a world.
 *
 * @param head pointer to the head of the list of objects
 * @param obj pointer to the object to be appended
 */
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

/**
 * @brief This function will free the memory allocated for a list of objects in
 * a world.
 *
 * @param head pointer to the head of the list of objects
 */
void	free_objects(t_object **head)
{
	t_object	*aux;

	while (*head)
	{
		free_matrix((*head)->transform);
		free_matrix((*head)->inverse);
		free_matrix((*head)->transpose_inverse);
		if ((*head)->type == SPHERE)
			free((*head)->shape.sphere);
		else if ((*head)->type == PLANE)
			free((*head)->shape.plane);
		else if ((*head)->type == CYLINDER)
			free((*head)->shape.cylinder);
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}
