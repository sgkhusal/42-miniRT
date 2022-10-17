/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/17 19:43:00 by sguilher         ###   ########.fr       */
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

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		return (ERROR);
	}
	return (fd);
}

int	handle_input(int argc, char *input[])
{
	int	fd;

	if (check_argc(argc) == ERROR)
		return (ERROR);
	if (check_file_extension(input[1]) == ERROR)
		return (ERROR);
	fd = open_file(input[1]);
	if (fd == ERROR)
		return (ERROR);
	return (OK);
}
