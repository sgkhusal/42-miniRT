/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:06:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/24 18:22:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	validate_color_chars_test(char *str, int expected)
{
	int	result;
	static int	n = 1;

	printf(GREY "validate_color_chars_test %d: " END, n);
	result = validate_color_chars(str);
	check_int_values(result, expected);
	n++;
}

void	validate_double_chars_test(char *str, int expected)
{
	int	result;
	static int	n = 1;

	printf(GREY "validate_double_chars_test %d: " END, n);
	result = validate_double_chars(str);
	check_int_values(result, expected);
	n++;
}

void	validate_coordinates_chars_test(char *str, int expected)
{
	int	result;
	static int	n = 1;

	printf(GREY "validate_coordinates_chars_test %d: " END, n);
	result = validate_coordinates_chars(str);
	check_int_values(result, expected);
	n++;
}

void	validate_nb_chars_test(char *str, int expected)
{
	int	result;
	static int	n = 1;

	printf(GREY "validate_nb_chars_test %d: " END, n);
	result = validate_nb_chars(str);
	check_int_values(result, expected);
	n++;
}

void	validate_input_tests(void)
{
	printf(YELLOW "validate_input_tests:\n" END);
	validate_color_chars_test("255,255,255", OK);
	validate_color_chars_test("25.5,255,255", ERROR);
	validate_color_chars_test("255,255,hi", ERROR);
	validate_color_chars_test("255,0,-50", ERROR);
	validate_color_chars_test("255.255.255", ERROR);
	validate_double_chars_test("1.0", OK);
	validate_double_chars_test("21.42", OK);
	validate_double_chars_test("2", OK);
	validate_double_chars_test("2.837895792857", OK);
	validate_double_chars_test("1,0", ERROR);
	validate_double_chars_test("-1.0", ERROR);
	validate_double_chars_test("a", ERROR);
	validate_coordinates_chars_test("50.0,0.0,20.6", OK);
	validate_coordinates_chars_test("0.0,0.0,1.0", OK);
	validate_coordinates_chars_test("-40.0,50.0,0.0", OK);
	validate_coordinates_chars_test("-40.0,50.0,a", ERROR);
	validate_nb_chars_test("45", OK);
	validate_nb_chars_test("450", OK);
	validate_nb_chars_test("-45", ERROR);
	validate_nb_chars_test("45.5", ERROR);
	validate_nb_chars_test("a", ERROR);
}
