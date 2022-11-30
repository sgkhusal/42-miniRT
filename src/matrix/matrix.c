/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:05:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/30 14:57:21 by elraira-         ###   ########.fr       */
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
 * @brief This function is an auxiliary function to print a given matrix.
 * It is used for debugging purposes.
 *
 * @param m matrix to be printed
 */
void	print_matrix(t_matrix m) /* remove */
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

/**
 * @brief This function will compare two matrices and return 1 if they are
 * identical and 0 if they are different. It is used for debugging purposes.
 *
 * @param m1 first matrix to be compared
 * @param m2 second matrix to be compared
 * @return int 1 if the matrices are identical and 0 if they are different
 */
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
