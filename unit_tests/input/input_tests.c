/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:19:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/20 18:33:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	check_argc_test(int argc, int expected)
{
	int			result;
	static int	n = 1;

	printf(GREY "check_argc_test %d: " END, n);
	result = check_argc(argc);
	check_int_values(result, expected);
	n++;
}

void	check_file_extension_test(char *file, int expected)
{
	int			result;
	static int	n = 1;

	printf(GREY "check_file_extension_test %d: " END, n);
	result = check_file_extension(file);
	check_int_values(result, expected);
	n++;
}

void	open_file_test(char *file, int expected)
{
	int			result;
	static int	n = 1;

	printf(GREY "open_file %d: " END, n);
	result = open_file(file);
	check_int_values(result, expected);
	if (result != ERROR)
		close(result);
	n++;
}

void	read_file_test(int fd, int expected)
{
	int			result;
	char		*content;
	static int	n = 1;

	printf(GREY "read_file %d: " END, n);
	content = ft_strdup("");
	result = read_file(fd, &content);
	check_int_values(result, expected);
	if (content && result == OK)
		free(content);
	if (fd > -1)
		close(fd);
	n++;
}

void	is_empty_file_test(char *file, int expected)
{
	int			fd;
	int			result;
	char		*content;
	static int	n = 1;

	printf(GREY "is_empty_file_test %d: " END, n);
	fd = open(file, O_RDONLY);
	content = ft_strdup("");
	read_file(fd, &content);
	result = is_empty_file(content);
	check_int_values(result, expected);
	close(fd);
	if (result == NO)
		free(content);
}

void	input_tests(void)
{
	int	fd;

	printf(YELLOW "Input tests: " END "\n");
	check_argc_test(2, OK);
	check_argc_test(1, ERROR);
	check_argc_test(3, ERROR);
	check_file_extension_test("scene.rt", OK);
	check_file_extension_test("a.rt", OK);
	check_file_extension_test(".rt", ERROR);
	check_file_extension_test("scene.pdf", ERROR);
	check_file_extension_test("scene.ri", ERROR);
	open_file_test("unit_tests.h", 3);
	open_file_test("../minirt.h", 3);
	open_file_test("hello", ERROR);
	open_file_test("../tuple/point.c", ERROR);
	open_file_test("no_permission.rt", ERROR);
	fd = open("../scenes/cool.rt", O_RDONLY);
	read_file_test(fd, OK);
	fd = open("../scenes/invalid/empty.rt", O_RDONLY);
	read_file_test(fd, OK);
	fd = open("hello", O_RDONLY);
	read_file_test(fd, ERROR);
	read_file_test(5, ERROR);
	is_empty_file_test("../scenes/cool.rt", NO);
	is_empty_file_test("../scenes/invalid/empty.rt", YES);
}
