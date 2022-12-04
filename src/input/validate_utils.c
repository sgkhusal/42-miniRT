/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:24:56 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 09:48:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will validate the information contained in the line
 * passed as property of each element. It will check if the information string
 * exists and iterate through it retuning the number of information found which
 * is different for each object.
 *
 * @param infos information string
 * @return int number of information found
 */
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

/**
 * @brief This function is an auxiliary function to validate information that
 * must be given in double format. It will check if the string is a valid double
 * and if it is positive.
 *
 * @param str the string to be validated
 * @return int OK if the string is valid, ERROR otherwise
 */
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

/**
 * @brief This function is an auxiliary function to validate information that
 * must be given in RGB format. It will check if the string is a valid RGB
 * format and if the values are between 0 and 255.
 *
 * @param rgb_str the string to be validated
 * @return int OK if the string is valid, ERROR otherwise
 */
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

/**
 * @brief This function is an auxiliary function to validate information that
 * must be given in x,y,z coordinates format. It will check if the string is a
 * valid x,y,z coordinates format.
 *
 * @param str the string to be validated
 * @return int OK if the string is valid, ERROR otherwise
 */
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

/**
 * @brief This function is an auxiliary function to validate information that
 * must be given in number format. It will check if the string is a valid number
 * and if it is positive.
 *
 * @param str the string to be validated
 * @return int OK if the string is valid, ERROR otherwise
 */
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
