/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 19:05:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_cylinder_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[3]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[4]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[5]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_cylinder(char *line, t_rt *rt)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_cylinder"));
	if (total_infos(infos) != 6)
		status = print_error_msg2("to many or few arguments for cylinder",
			line);
	else if (validate_cylinder_chars(infos) == ERROR)
		status = ERROR;
	/* else if (set_cylinder(&infos[1], &rt->cylinder) == ERROR)
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
