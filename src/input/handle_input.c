/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 12:02:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will check if arguments passed at the program execution
 * are valid, which means exactly two arguments, the first one being the program
 * name, and the second one being the scene file.
 *
 * @param argc number of arguments
 * @return int OK if arguments are valid, ERROR if not.
 */
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

/**
 * @brief This function will try to open and read the scene file passed as
 * argument and parse them into lines. If the file is not found, or an error
 * occurs while reading the file, or the file is empty, an error message will
 * be printed and the pointers will be freed.
 *
 * @param fd file descriptor
 * @return char** array of strings containing the scene file lines
 */
static char	**get_lines(int fd)
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

/**
 * @brief This function will validate the arguments passed to the program as
 * well as the scene file to be rendered. It will make sure that there are
 * two arguments, that the second argument is a .rt file, and that the file
 * exists and is readable and also that the mandatory elements are present
 * (A, C, L).
 *
 * @param argc number of arguments passed to the program.
 * @param filename name of the scene file to be rendered.
 * @param rt pointer to the t_rt structure.
 * @return int OK if the arguments are valid, ERROR otherwise.
 */
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
