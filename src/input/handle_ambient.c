/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:35 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 08:57:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will validate the information of the ambient light.
 * The first info is the ratio of the ambient light, which must be between 0
 * and 1, a double. The second info is the color of the ambient light, which
 * must be a valid color.
 *
 * @param infos the information of the ambient light, which is a string
 * @return int 0 if the information is valid, 1 otherwise
*/
static int	validate_ambient_chars(char **infos)
{
	if (validate_double_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[2]) == ERROR)
		return (ERROR);
	return (OK);
}

/**
 * @brief This function will handle the ambient light information. It will
 * split the information in the string, validate the information, transform
 * the information in the correct type and store it in the scene. Then, it will
 * free the information.
 *
 * @param line the information of the ambient light
 * @param amb the ambient light
 * @return int ERROR if the information is invalid, OK otherwise
 */
int	handle_ambient_light(char *line, t_vector *amb)
{
	char		**infos;
	int			status;
	double		ratio;
	t_vector	color;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_ambient_light"));
	if (total_infos(infos) != 3)
		status = print_error_msg2(
				"to many or few arguments for ambient light A: ",
				"[ambient lighting ratio] [rgb color]");
	else if (validate_ambient_chars(infos) == ERROR)
		status = ERROR;
	else
	{
		ratio = transform_ratio(infos[1], &status);
		color = transform_color(infos[2], &status);
		*amb = multiply_vector_by_scalar(color, ratio);
	}
	free_array(infos);
	return (status);
}

/**
 * @brief Set the ambient light variables to each object in the scene.
 *
 * @param objects the t_objects list
 * @param amb the ambient light
 */
void	set_ambient_light(t_object **objects, t_vector amb)
{
	t_object	*obj;

	obj = *objects;
	while (obj)
	{
		obj->material.ambient = amb;
		obj = obj->next;
	}
}
