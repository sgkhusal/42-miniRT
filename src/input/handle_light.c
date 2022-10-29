/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:53:11 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_light_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_light(char *line, t_light *light)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_light"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for light", line);
	else if (validate_light_chars(infos) == ERROR)
		status = ERROR;
	else
	{
		light->position = transform_coordinates(infos[1], &status);
		light->brightness = transform_ratio(infos[2], &status);
		light->color = transform_color(infos[3], &status);
	}
	free_array(infos);
	return (status);
}
