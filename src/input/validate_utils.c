/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:24:56 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/24 18:31:14 by sguilher         ###   ########.fr       */
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

int	validate_double_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && !ft_isdigit(str[i]))
		{
			if (str[i] == '-')
				return (print_error_msg2("number must be positive: ", str));
			return (print_error_msg2("Invalid character in lighting ratio: ",
				str));
		}
		i++;
	}
	return (OK);
}

int	validate_color_chars(char *rgb_str)
{
	int	i;

	i = 0;
	while (rgb_str[i])
	{
		if (rgb_str[i] != ',' && !ft_isdigit(rgb_str[i]))
		{
			if (rgb_str[i] == '-')
				return (print_error_msg2("color numbers must be positive: ",
					rgb_str));
			return (print_error_msg2("invalid character for color: ", rgb_str));
		}
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
		if (str[i] != '.' && str[i] != ',' && str[i] != '-'
			&& !ft_isdigit(str[i]))
			return (print_error_msg2("Invalid character in coordinates: ",
				str));
		i++;
	}
	return (OK);
}

int	validate_nb_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-')
				return (print_error_msg2("number must be positive: ", str));
			return (print_error_msg2("invalid character for number: ", str));
		}
		i++;
	}
	return (OK);
}
