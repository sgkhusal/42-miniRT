/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 19:21:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "tuples.h"

/**
 * @brief struct to store matrix values and dimensions 
 */
typedef struct s_matrix
{
	double	**matrix;
	int		size;

}				t_matrix;

/**
 * @brief struct which stores shearing matrix values (x in proportion to y, 
 * z in proportion to y, etc.) 
 */
typedef struct s_shearing
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
}				t_shearing;

/* matrix functions */
t_matrix	create_matrix(int size);
void		free_matrix(t_matrix m);
t_matrix	identity_matrix(int size);

/* matrix operations functions */
t_matrix	transposed_matrix(t_matrix matrix);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_vector	multiply_matrix_by_vector(t_matrix m, t_vector v);
t_point		multiply_matrix_by_point(t_matrix m, t_point p);
double		get_determinant(t_matrix m);
t_matrix	get_submatrix(t_matrix m, int row, int column);
double		get_minor(t_matrix m, int row, int column);
double		get_cofactor(t_matrix m, int row, int column);
t_matrix	inverse_matrix(t_matrix m);

/* transformation matrix functions */
t_matrix	translation_matrix(double x, double y, double z);
t_matrix	scaling_matrix(double x, double y, double z);
t_matrix	rotation_x_matrix(double radians);
t_matrix	rotation_y_matrix(double radians);
t_matrix	rotation_z_matrix(double radians);
t_matrix	shearing_matrix(t_shearing s);

#endif
