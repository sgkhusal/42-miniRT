/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/23 22:02:51 by sguilher         ###   ########.fr       */
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

int	handle_input(int argc, char *filename, t_rt	*rt)
{
	int		fd;
	char	*content;

	if (check_argc(argc) == ERROR)
		return (ERROR);
	if (check_file_extension(filename) == ERROR)
		return (ERROR);
	fd = open_file(filename);
	if (fd == ERROR)
		return (ERROR);
	content = ft_strdup("");
	if (read_file(fd, &content) == ERROR)
		return (ERROR);
	if (handle_content(content, rt) == ERROR)
		return (ERROR);
	return (OK);
}
