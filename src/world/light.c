/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:21:36 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 11:38:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Creates a new point light source by allocating memory for it and
 * initializing its atritbutes with the values given as parameters.

 * @param position the position of the light source
 * @param intensity the intensity of the light
 * @return t_light* a pointer to the new light
 */
t_light	*create_point_light(t_point position, t_vector intensity)
{
	t_light	*light;

	light = NULL;
	light = malloc(sizeof(t_light));
	if (!light)
		minirt_malloc_error("create_light");
	light->position = position;
	light->intensity = intensity;
	light->next = NULL;
	return (light);
}

/**
 * @brief Adds a new light source to the list of lights.
 *
 * @param head the head of the list of lights
 * @param light the light to be added
 */
void	append_light(t_light **head, t_light *light)
{
	t_light	*aux;

	if (*head == NULL)
	{
		*head = light;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = light;
}

/**
 * @brief Will free the memory allocated for the list of lights.
 *
 * @param head the head of the list of lights
 */
void	free_lights(t_light **head)
{
	t_light	*aux;

	while (*head)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}
