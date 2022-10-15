/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:33:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/15 14:46:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
