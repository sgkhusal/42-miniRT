/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:10:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/29 17:48:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief the atod() function converts a string to a double.
 * 
 * @param nb string to be converted
 * @return double converted string
 */
double	ft_atod(char *nb)
{
	double	n;
	int		point;
	int		size;

	size = ft_strlen(nb);
	point = 0;
	while (nb[point] != '.' && point < size)
		point++;
	if (point == size)
		return (ft_atoi(nb));
	ft_memmove(nb + point, nb + point + 1, size - point);
	n = ft_atoi(nb);
	n /= pow(10, size - point - 1);
	return (n);
}

/**
 * @brief will parse the input file by splitting the string by the delimiter (',').
 * Then, it will check if the file contains exactly the number of elements specified in the subject.
 * 
 * @param line line to be parsed
 * @param c  delimiter
 * @param size_expected number of elements expected
 * @param status status of the parsing
 * @return char** parsed string
 */
char	**parse_input(char *line, char c, int size_expected, int *status)
{
	char	**parsed;

	parsed = NULL;
	parsed = ft_split(line, c);
	if (!parsed)
		*status = print_error_msg2("malloc error on parse_input: ", line);
	else if (total_infos(parsed) != size_expected)
	{
		free_array(parsed);
		*status = print_error_msg2("to many or few arguments in ", line);
	}
	return (parsed);
}
