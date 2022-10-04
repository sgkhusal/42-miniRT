/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/04 15:35:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <stdio.h> // printf
# include <math.h>

# include "mlx_utils.h"

typedef union u_color
{
	int		color;
	char	rgb[4];
}				t_color;

/**
 * @param x x axis value (right)
 * @param y y axis value (up)
 * @param z z axis value (out of screen)
 * @param w type (1 = point, 0 = vector)
 */
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

typedef struct s_ray
{
	t_tuple	*origin;
	t_tuple	*direction;
}				t_ray;

// input
void	handle_input(int argc, char *input[]);

// colors
int		rgb_to_int(short int red, short int green, short int blue);

// tuples
t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple	*create_point(double x, double y, double z);
t_tuple	*create_vector(double x, double y, double z);
t_tuple	*add_tuples(t_tuple tuple1, t_tuple tuple2);
t_tuple	*multiply_tuple_by_scalar(t_tuple tuple, double scalar);


// close
int		close_minirt(t_mlx *mlx);

// error
int		minirt_error(t_mlx *mlx, char *msg);
void	minirt_malloc_error(char *function);

#endif
