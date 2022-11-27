/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:42:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 18:10:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	check_int_values(int result, int expected)
{
	if (result == expected)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}
