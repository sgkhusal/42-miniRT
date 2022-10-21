/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 19:00:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_plane_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_plane(char *line, t_rt *rt)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_plane"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for plane", line);
	else if (validate_plane_chars(infos) == ERROR)
		status = ERROR;
	/* else if (set_plane(&infos[1], &rt->plane) == ERROR)
		status = ERROR; */
	// transform
	// validate range:
	// ∗ x,y,z coordinates: 0.0,0.0,20.6
	// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
	// ∗ R,G,B colors in range [0-255]: 10, 0, 255
	if (status == ERROR)
	{
		free_array(infos);
		rt->oi = 0; //
		return (ERROR);
	}
	return (OK);
}
