/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:33:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 15:48:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief In this function, a matrix of cofactors is created. The matrix of
 * cofactor contains the cofactors of each element of the original matrix.
 * It is auxiliary to the calculation of the inverse matrix.
 *
 * @param m the original matrix
 * @return t_matrix the matrix of cofactors
 */
static t_matrix	cofactor_matrix(t_matrix m)
{
	t_matrix	cofactor;
	int			i;
	int			j;

	cofactor = create_matrix(m.size);
	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
			cofactor.matrix[i][j] = get_cofactor(m, i, j);
	}
	return (cofactor);
}

/**
 * @brief Inverting matrix is the key to transforming and deforming objects
 * in a ray tracer.
 * Here, we opted to return and identity matrix if the determinant is 0, which
 * means the matrix is not invertible.
 *
 * @param m matrix to be inverted
 * @return t_matrix the resulting matrix
 */
t_matrix	inverse_matrix(t_matrix m)
{
	t_matrix	cofactor;
	t_matrix	inverse;
	double		determinant;
	int			i;
	int			j;

	determinant = get_determinant(m);
	if (check_double_values(determinant, 0))
		return (identity_matrix(m.size));
	cofactor = cofactor_matrix(m);
	inverse = transposed_matrix(cofactor);
	free_matrix(cofactor);
	i = 0;
	while (i < inverse.size)
	{
		j = 0;
		while (j < inverse.size)
		{
			inverse.matrix[i][j] /= determinant;
			j++;
		}
		i++;
	}
	return (inverse);
}
