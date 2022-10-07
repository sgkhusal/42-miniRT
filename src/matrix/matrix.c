/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:05:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/07 14:21:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	**create_matrix(int rows, int columns)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(rows * sizeof(int *));
	if (!matrix)
		minirt_malloc_error("create_matrix");
	i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)malloc(columns * sizeof(int));
		if (!matrix[i])
			minirt_malloc_error("create_matrix");
		i++;
	}
	return (matrix);
}

void	free_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_matrix(int **matrix, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/* identity = 1 0 0 0
              0 1 0 0
              0 0 1 0
              0 0 0 1 */
int	**identity_matrix(int **matrix, int rows, int columns)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = create_matrix(rows, columns);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
		if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		printf("\n");
		i++;
	}
}
