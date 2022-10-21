/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:24:56 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 14:41:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	total_infos(char **infos)
{
	int	i;

	i = 0;
	if (!infos || !*infos)
		return (0);
	while (infos[i])
		i++;
	return (i);
}

int	validate_color_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (print_error_msg2("Invalid character in color: ",
				str));
		i++;
	}
	return (OK);
}

int	validate_coordinates_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != ',' && !ft_isdigit(str[i]))
			return (print_error_msg2("Invalid character in coordinates: ",
				str));
		i++;
	}
	return (OK);
}
