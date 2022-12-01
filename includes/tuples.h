/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:20:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 21:01:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

/**
 * @brief vector struct
 * @param x x axis value (right)
 * @param y y axis value (up)
 * @param z z axis value (out of screen)
 * @param w type (1 = point, 0 = vector)
 */
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

/**
 * @brief point struct
 * @param x x axis value (right)
 * @param y y axis value (up)
 * @param z z axis value (out of screen)
 * @param w type (1 = point, 0 = vector)
 */
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_point;

/* tuple functions */
t_point			set_point(double x, double y, double z);
t_vector		set_vector(double x, double y, double z);
double			vector_length(t_vector vector);
t_vector		add_vectors(t_vector a, t_vector b);
t_vector		subtract_vectors(t_vector a, t_vector b);
t_vector		subtract_points(t_point a, t_point b);
t_point			add_point_and_vector(t_point point, t_vector vector);
t_point			subtract_point_and_vector(t_point point, t_vector vector);
t_vector		negative_vector(t_vector vector);
t_vector		multiply_vector_by_scalar(t_vector vector, double scalar);
t_vector		normalize_vector(t_vector vector);
double			scalar_product(t_vector a, t_vector b);
t_vector		cross_product(t_vector a, t_vector b);

#endif
