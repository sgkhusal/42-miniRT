/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:37:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:40:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			printf("%f ", m.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
