/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:44:45 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/20 18:49:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_file_extension(char *file)
{
	int	len;

	if (!file)
	{
		print_error_msg("invalid file name");
		return (ERROR);
	}
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

static int	read_error(int fd, char **content)
{
	print_error_msg("error reading file");
	if (content && *content)
		free(*content);
	if (fd > -1)
		close(fd);
	return (ERROR);
}

int	read_file(int fd, char **content)
{
	int		gnl;
	char	*tmp;
	char	*line;

	gnl = GNL_READ_LINE;
	while (gnl > 0)
	{
		line = NULL;
		tmp = NULL;
		gnl = get_next_line(fd, &line);
		if (gnl == GNL_READ_LINE || gnl == GNL_EOF)
		{
			tmp = ft_strjoin(*content, line);
			free(*content);
			free(line);
			if (!tmp)
				return (print_error_msg("malloc error"));
			*content = tmp;
		}
	}
	if (gnl == GNL_ERROR)
		return (read_error(fd, content));
	close(fd);
	return (OK);
}

int	is_empty_file(char *content)
{
	if (!content || !*content || (content[0] == '\n' && !content[1]))
	{
		if (content)
			free(content);
		return (YES);
	}
	return (NO);
}
