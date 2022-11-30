/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:05:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/30 16:40:25 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will create a quadratic matrix of a given size by
 * allocating memory for the matrix and its elements.
 *
 * @param size size of each side of the matrix
 * @return t_matrix the resulting matrix
 */
t_matrix	create_matrix(int size)
{
	t_matrix	m;
	int			i;

	m.size = size;
	m.matrix = (double **) malloc(sizeof(double *) * size);
	if (!m.matrix)
		minirt_malloc_error("create_matrix");
	i = 0;
	while (i < size)
	{
		m.matrix[i] = (double *)malloc(sizeof(double) * size);
		if (!m.matrix[i])
			minirt_malloc_error("create_matrix");
		i++;
	}
	return (m);
}

/**
 * @brief This function will free the memory allocated for a matrix.
 *
 * @param m matrix to be freed
 */
void	free_matrix(t_matrix m)
{
	int	i;

	i = 0;
	while (i < m.size)
	{
		free(m.matrix[i]);
		i++;
	}
	free(m.matrix);
}

/**
 * @brief This function will create a matrix and then fill it with the
 * identity matrix.
 * identity = 1 0 0 0
 *            0 1 0 0
 *            0 0 1 0
 *            0 0 0 1
 *
 * @param size size of each side of the matrix
 * @return t_matrix the resulting matrix
 */
t_matrix	identity_matrix(int size)
{
	t_matrix	m;
	int			i;
	int			j;

	m = create_matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				m.matrix[i][j] = 1;
			else
				m.matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}
