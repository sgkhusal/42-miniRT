/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:35 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 12:28:07 by sguilher         ###   ########.fr       */
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

int	handle_ambient_light(char *line, t_ambient *amb)
{
	char	**infos;
	int		status;

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
		amb->ratio = transform_ratio(infos[1], &status);
		amb->intensity = transform_color(infos[2], &status);
		amb->intensity = multiply_vector_by_scalar(amb->intensity, amb->ratio); // verificar se isso é correto
	}
	free_array(infos);
	return (status);
}
