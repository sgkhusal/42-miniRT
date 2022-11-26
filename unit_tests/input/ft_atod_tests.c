/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:52:51 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 14:56:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	ft_atod_test(char *input, double expected)
{
	double		result;
	static int	n = 1;

	printf(GREY "ft_atod_test %d: " END, n);
	result = ft_atod(input);
	if (check_double_values(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	ft_atod_tests(void)
{
	char	input[20];

	input[0] = '0';
	input[1] = '.';
	input[2] = '2';
	input[2] = '\0';
	printf(YELLOW "atod tests: " END "\n");
	ft_atod_test(ft_memcpy(input, "0.2", 4), 0.2);
	ft_atod_test(ft_memcpy(input, "0.0", 4), 0.0);
	ft_atod_test(ft_memcpy(input, "1.0", 4), 1.0);
	ft_atod_test(ft_memcpy(input, "20.6", 5), 20.6);
	ft_atod_test(ft_memcpy(input, "-1.0", 5), -1.0);
	ft_atod_test(ft_memcpy(input, "180", 4), 180);
	ft_atod_test(ft_memcpy(input, "21.42", 6), 21.42);
	ft_atod_test(ft_memcpy(input, "100000.0555", 15), 100000.0555);
	ft_atod_test(ft_memcpy(input, "-100000.0555", 17), -100000.0555);
	ft_atod_test(ft_memcpy(input, "-1000000555.", 17), -1000000555.0);
}
