/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:21:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/10 15:48:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will multiply two equal size square matrices.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return t_matrix The resulting matrix.
 */
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;

	if (m1.size != m2.size)
	{
		printf("Error: matrix size mismatch\n");
		return (m1);
	}
	i = -1;
	res = create_matrix(m1.size);
	while (++i < m1.size)
	{
		j = -1;
		while (++j < m2.size)
		{
			k = -1;
			res.matrix[i][j] = 0;
			while (++k < m1.size)
				res.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
		}
	}
	return (res);
}

/**
 * @brief This function will multiply a given 4x4 matrix by a given vector, and
 * return a vector.
 *
 * @param m The matrix to be multiplied.
 * @param v The given vector
 * @return t_vector The resulting vector.
 */
t_vector	multiply_matrix_by_vector(t_matrix m, t_vector v)
{
	t_vector	res;

	res.x = m.matrix[0][0] * v.x + m.matrix[0][1] * v.y
		+ m.matrix[0][2] * v.z + m.matrix[0][3] * v.w;
	res.y = m.matrix[1][0] * v.x + m.matrix[1][1] * v.y
		+ m.matrix[1][2] * v.z + m.matrix[1][3] * v.w;
	res.z = m.matrix[2][0] * v.x + m.matrix[2][1] * v.y
		+ m.matrix[2][2] * v.z + m.matrix[2][3] * v.w;
	res.w = m.matrix[3][0] * v.x + m.matrix[3][1] * v.y
		+ m.matrix[3][2] * v.z + m.matrix[3][3] * v.w;
	return (res);
}

/**
 * @brief This function will multiply a given 4x4 matrix by a given point, and
 * return a point.
 *
 * @param m The matrix to be multiplied.
 * @param p The given point
 * @return t_point The resulting point.
 */
t_point	multiply_matrix_by_point(t_matrix m, t_point p)
{
	t_point	res;

	res.x = m.matrix[0][0] * p.x + m.matrix[0][1] * p.y
		+ m.matrix[0][2] * p.z + m.matrix[0][3] * p.w;
	res.y = m.matrix[1][0] * p.x + m.matrix[1][1] * p.y
		+ m.matrix[1][2] * p.z + m.matrix[1][3] * p.w;
	res.z = m.matrix[2][0] * p.x + m.matrix[2][1] * p.y
		+ m.matrix[2][2] * p.z + m.matrix[2][3] * p.w;
	res.w = m.matrix[3][0] * p.x + m.matrix[3][1] * p.y
		+ m.matrix[3][2] * p.z + m.matrix[3][3] * p.w;
	return (res);
}
