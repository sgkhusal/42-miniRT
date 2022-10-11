/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 20:40:36 by sguilher         ###   ########.fr       */
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
t_matrix	transposed_matrix(t_matrix matrix)
{
	t_matrix	transposed;
	int			i;
	int			j;

	transposed = create_matrix(matrix.size);
	i = 0;
	while (i < matrix.size)
	{
		j = 0;
		while (j < matrix.size)
		{
			transposed.matrix[i][j] = matrix.matrix[j][i];
			j++;
		}
		i++;
	}
	return (transposed);
}

/**
 * @brief A submatrix is what is left when you delete a single row and column
 * from a matrix.
 *
 * @param m The matrix from which a submatrix will be created.
 * @param row The row to be deleted in the matrix.
 * @param column The column to be deleted in the matrix.
 * @return t_matrix The created submatrix.
 */
t_matrix	get_submatrix(t_matrix m, int row, int column)
{
	t_matrix	submatrix;
	int			i;
	int			j;
	int			k;
	int			l;

	submatrix = create_matrix(m.size - 1);
	i = -1;
	k = 0;
	while (++i < submatrix.size)
	{
		j = -1;
		l = 0;
		if (k == row)
			k++;
		while (++j < submatrix.size)
		{
			if (l == column)
				l++;
			submatrix.matrix[i][j] = m.matrix[k][l];
			l++;
		}
		k++;
	}
	return (submatrix);
}

/**
 * @brief The minor is the determinant of the submatrix.
 *
 * @param m The matrix from which the submatrix wil be obtained.
 * @return double The minor of the submatrix.
 */
double	get_minor(t_matrix m, int row, int column)
{
	t_matrix	submatrix;
	double		minor;

	submatrix = get_submatrix(m, row, column);
	minor = get_determinant(submatrix);
	free_matrix(submatrix);
	return (minor);
}

/**
 * @brief Cofactors are are minors that have (possibly) had their sign changed.
 * If row + column is an odd number, then minor is negated. Otherwise, it is
 * returned as is.
 * @param m The matrix from which the cofactor will be obtained.
 * @return double The cofactor of the minor.
 */
double	get_cofactor(t_matrix m, int row, int column)
{
	double	minor;

	minor = get_minor(m, row, column);
	if ((column + row) % 2 == 0)
		return (minor);
	else
		return ((-1) * minor);
}

double	get_determinant(t_matrix m)
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
			det += m.matrix[0][i] * get_cofactor(m, 0, i);
			i++;
		}
	}
	return (det);
}
