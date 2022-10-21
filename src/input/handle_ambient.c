/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:35 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 15:40:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_lighting_ratio_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && !ft_isdigit(str[i]))
			return (print_error_msg2("Invalid character in lighting ratio: ",
				str));
		i++;
	}
	return (OK);
}

static int validate_ambient_chars(char **infos)
{
	if (validate_lighting_ratio_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[2]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_ambient_light(char *line, t_rt *rt)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_ambient_light"));
	if (total_infos(infos) != 3)
		status = print_error_msg("to many or few arguments for ambient light");
	else if (validate_ambient_chars(infos) == ERROR)
		status = ERROR;
	/* else if (set_ambient_light(&infos[1], &rt->ambient_light) == ERROR)
		status = ERROR; */
	// transform
	// validate range
	// ∗ ambient lighting ratio in range [0.0,1.0]: 0.2
	//∗ R,G,B colors in range [0-255]: 255, 255, 255
	if (status == ERROR)
	{
		free_array(infos);
		rt->oi = 0; //
		return (ERROR);
	}
	return (OK);
}
