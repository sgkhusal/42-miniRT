/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:44:45 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/28 22:08:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Checks if the file exists and if its extension is .rt.
 * 
 * @param file name of the file
 * @return int 1 if the file extension is .rt, 0 if not
 */
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

/**
 * @brief Opens the .rt input files. Returns an error if the file 
 * can't be opened.
 * 
 * @param file name of the file to be opened
 * @return int file descriptor or ERROR if the file can't be opened
 */
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

/**
 * @brief Returns an error if the file couldn't be read and
 * frees the memory allocated for the file content. Then, closes the file
 * descriptor.
 * 
 * @param fd file descriptor
 * @param content file content
 * @return int ERROR as the file couldn't be read
 */
static int	read_error(int fd, char **content)
{
	print_error_msg("error reading file");
	if (content && *content)
		free(*content);
	if (fd > -1)
		close(fd);
	return (ERROR);
}

/**
 * @brief Reads the file content using get_next_line. Returns an error if the
 * file couldn't be read. After reading the file, it closes the file descriptor
 * and frees the memory allocated for the file content.
 * 
 * @param fd file descriptor
 * @param content file content
 * @return int OK if the file was read successfully, ERROR if not
 */
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
	close(fd);
	if (gnl == GNL_ERROR)
		return (read_error(fd, content));
	return (OK);
}
