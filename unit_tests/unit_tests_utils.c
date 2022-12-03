/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:42:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 19:23:54 by sguilher         ###   ########.fr       */
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

int	check_equal_matrices(t_matrix m1, t_matrix m2)
{
	int	i;
	int	j;

	if (m1.size != m2.size)
		return (FALSE);
	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			if (!check_double_values(m1.matrix[i][j], m2.matrix[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
