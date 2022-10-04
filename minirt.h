/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/04 18:56:00 by sguilher         ###   ########.fr       */
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

typedef struct s_sphere
{
	t_tuple	*center;
	double	radius;
	t_color	color;
}				t_sphere;

/**
 * @param t1 the distance from the ray origin to the first intersection
 * @param t2 the distance from the ray origin to the second intersection
 * @param count the number of intersections. If there's only one intersection,
 * count = 2 and t2 = t1 and if there are no intersections, count = 0.
 */
typedef struct s_intersection
{
	double	t1;
	double	t2;
	int 	count;
}				t_intersection;

// input
void	handle_input(int argc, char *input[]);

// colors
int		rgb_to_int(short int red, short int green, short int blue);
t_color	*create_color(short int red, short int green, short int blue);

// tuples
t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple	*create_point(double x, double y, double z);
t_sphere	*create_sphere(t_tuple *center, double radius, t_color *color);
t_tuple	*create_vector(double x, double y, double z);
t_tuple	*add_tuples(t_tuple tuple1, t_tuple tuple2);
t_tuple	*multiply_tuple_by_scalar(t_tuple tuple, double scalar);
t_tuple	*subtract_tuples(t_tuple tuple1, t_tuple tuple2);
double	tuple_length(t_tuple *tuple);
t_intersection	*sphere_intersection(t_ray *ray, t_sphere *sphere);
double	scalar_product(t_tuple tuple1, t_tuple tuple2);

// rays
t_ray	*create_ray(t_tuple *origin, t_tuple *direction);
t_tuple	*ray_position(t_ray *ray, double distance);

// close
int		close_minirt(t_mlx *mlx);

// error
int		minirt_error(t_mlx *mlx, char *msg);
void	minirt_malloc_error(char *function);

#endif
