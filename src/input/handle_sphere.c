/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:58 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 19:01:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_sphere_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_sphere(char *line, t_rt *rt)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_sphere"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for sphere", line);
	else if (validate_sphere_chars(infos) == ERROR)
		status = ERROR;
	/* else if (set_sphere(&infos[1], &rt->sphere) == ERROR)
		status = ERROR; */
	// transform
	// validate range:
	// ∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
	// ∗ the sphere diameter: 12.6
	// ∗ R,G,B colors in range [0-255]: 10, 0, 255
	if (status == ERROR)
	{
		free_array(infos);
		rt->oi = 0; //
		return (ERROR);
	}
	return (OK);
}

