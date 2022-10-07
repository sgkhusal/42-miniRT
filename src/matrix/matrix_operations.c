/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/07 15:25:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_matrix multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix res;
	int i;
	int j;
	int k;

	if (m1.size != m2.size)
	{
		printf("Error: matrix size mismatch\n");
		return (m1);
	}
	i = 0;
	res = create_matrix(m1.size);
	while(i < m1.size)
	{
		j = 0;
		while (j < m2.size)
		{
			k = 0;
			res.matrix[i][j] = 0;
			while (k < m1.size)
			{
				res.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
				k++;
			}
			j++;
		}
	}
}

