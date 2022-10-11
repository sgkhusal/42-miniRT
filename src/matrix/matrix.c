/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:05:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 16:01:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	print_matrix(t_matrix m) // remove
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

/* identity = 1 0 0 0
              0 1 0 0
              0 0 1 0
              0 0 0 1 */
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

bool	check_equal_matrices(t_matrix m1, t_matrix m2)
{
	int	i;
	int	j;

	if (m1.size != m2.size)
		return (false);
	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			if (m1.matrix[i][j] != m2.matrix[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
