/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/20 20:29:21 by sguilher         ###   ########.fr       */
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

t_rt	handle_input(int argc, char *filename)
{
	int		fd;
	char	*content;

	if (check_argc(argc) == ERROR)
		exit (EXIT_FAILURE);
	if (check_file_extension(filename) == ERROR)
		exit (EXIT_FAILURE);
	fd = open_file(filename);
	if (fd == ERROR)
		exit (EXIT_FAILURE);
	content = ft_strdup("");
	if (read_file(fd, &content) == ERROR)
		exit (EXIT_FAILURE);
	return (handle_content(content));
}
