/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 19:02:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_light_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_light(char *line, t_rt *rt)
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
	/* else if (set_light(&infos[1], &rt->light) == ERROR)
		status = ERROR; */
	// transform
	// validate range:
	// ∗ x,y,z coordinates of the light point: 0.0,0.0,20.6
	// ∗ the light brightness ratio in range [0.0,1.0]: 0.6
	// ∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
	if (status == ERROR)
	{
		free_array(infos);
		rt->oi = 0; //
		return (ERROR);
	}
	return (OK);
}
