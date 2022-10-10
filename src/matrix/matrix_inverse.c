/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:33:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/10 16:40:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Checks whether the matrix can be inverted or not depending on its
 * determinant value
 *
 * @param matrix the matrix to be checked whether it can be inverted or not
 * @return true if the matrix can be inverted
 * @return false if the matrix can not be inverted
 */
bool	is_invertible(t_matrix matrix)
{
	if (get_determinant(matrix) != 0)
		return (true);
	return (false);
}

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
 * If matrix is not invertible, this function will return an identity matrix
 * (for future purposes) > talvez rever no futuro
 */
t_matrix	inverse_matrix(t_matrix m)
{
	t_matrix	cofactor;
	t_matrix	inverse;
	double		determinant;
	int			i;
	int			j;

	determinant = get_determinant(m);
	if (determinant == 0)
		return (identity_matrix(m.size));
	cofactor = cofactor_matrix(m);
	inverse = transposed_matrix(cofactor);
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
