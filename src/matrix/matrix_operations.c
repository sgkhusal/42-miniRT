/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/07 18:46:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Matrix transposition is a process of interchanging rows and columns
 * of a matrix. It will be used when translating normal vectors between objects
 * and the space. It is crucial when shading objects.
 *
 * @param matrix The matrix to be transposed.
 * @return t_matrix The transposed matrix.
 */
t_matrix	matrix_transpose(t_matrix matrix)
{
	t_matrix	res;
	int			i;
	int			j;

	res = create_matrix(matrix.size);
	i = 0;
	while (i < matrix.size)
	{
		j = 0;
		while (j < matrix.size)
		{
			res.matrix[i][j] = matrix.matrix[j][i];
			j++;
		}
		i++;
	}
	return (res);
}

t_matrix	get_submatrix(t_matrix m, int column)
{
	t_matrix submatrix;
	int i;
	int j;
	int k;

	submatrix = create_matrix(m.size - 1);
	i = 1;
	while (i < submatrix.size)
	{
		j = 0;
		k = 0;
		while (j < submatrix.size)
		{
			if (k != column)
			{
				submatrix.matrix[i - 1][j] = m.matrix[i][k];
				j++;
			}
			k++;
		}
		i++;
	}
	return (submatrix);
}

double	get_matrix_minor(t_matrix m, int column)
{
	t_matrix submatrix;

	submatrix = get_submatrix(m, column);
	if (column / 2 == 0)
		return (get_matrix_determinant(submatrix));
	else
		return (-get_matrix_determinant(submatrix));
}

double	get_matrix_determinant(t_matrix m)
{
	double	det;
	int		i;

	if (m.size == 2)
		det = m.matrix[0][0] * m.matrix[1][1]
			- m.matrix[0][1] * m.matrix[1][0];
	else
	{
		det = 0;
		i = 0;
		while (i < m.size)
		{
			det += m.matrix[0][i] * get_matrix_minor(m, i);
			i++;
		}
	}
	return (det);
}

/*
A submatrix is what is left when you delete a single row and column from
a matrix.
The minor of an element at row i and column j is the determinant of the
sub- matrix at (i,j).
Cofactors are are minors that have (possibly) had their sign changed.*/
