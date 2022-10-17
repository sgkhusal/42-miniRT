/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/17 17:49:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_argc(int argc)
{
	if (argc == 2)
		return (OK);
	if (argc < 2)
		print_error_msg("missing scene file");
	else
		print_error_msg("too many arguments");
	return (ERROR);
}

int	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 3], ".rt", 4))
	{
		print_error_msg("miniRT only supports *.rt files");
		return (ERROR);
	}
	return (OK);
}

int	handle_input(int argc, char *input[])
{
	if (check_argc(argc) == ERROR)
		return (ERROR);
	if (check_file_extension(input[1]) == ERROR)
		return (ERROR);
	return (OK);
}
