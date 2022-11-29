/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/28 22:23:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_argc(int argc)
{
	if (argc == 2)
		return (OK);
	if (argc < 2)
		print_error_msg("missing scene file");
	else
		print_error_msg("too many arguments");
	return (ERROR);
}

static char **get_lines(int fd)
{
	char	*content;
	char	**lines;

	content = ft_strdup("");
	if (read_file(fd, &content) == ERROR)
	{
		free(content);
		return (NULL);
	}
	lines = ft_split(content, '\n');
	free(content);
	if (!lines || !*lines)
	{
		if (lines)
			free_array(lines);
		print_error_msg("empty file");
		return (NULL);
	}
	return (lines);
}

int	handle_input(int argc, char *filename, t_rt	*rt)
{
	int		fd;
	char	**lines;

	if (check_argc(argc) == ERROR)
		return (ERROR);
	if (check_file_extension(filename) == ERROR)
		return (ERROR);
	fd = open_file(filename);
	if (fd == ERROR)
		return (ERROR);
	lines = get_lines(fd);
	if (lines == NULL)
		return (ERROR);
	if (handle_content(lines, rt) == ERROR)
		return (ERROR);
	return (OK);
}
