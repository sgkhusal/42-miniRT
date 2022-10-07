/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:42:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 16:05:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

bool	check_double_values(double a, double b)
{
	if (a - b > -0.00001 && a - b < 0.00001)
		return (true);
	return (false);
}
