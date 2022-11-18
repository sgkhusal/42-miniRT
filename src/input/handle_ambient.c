/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:35 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/18 18:48:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_ambient_chars(char **infos)
{
	if (validate_double_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[2]) == ERROR)
		return (ERROR);
	return (OK);
}

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
		status = print_error_msg2("to many or few arguments for ambient light",
				line);
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
