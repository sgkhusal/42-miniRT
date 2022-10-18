/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:19:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/17 22:37:09 by sguilher         ###   ########.fr       */
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

void	input_tests(void)
{
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
}
