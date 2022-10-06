/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 11:56:21 by sguilher         ###   ########.fr       */
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
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w; // TODO: verificar se será necessário
}				t_vector;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	w; // TODO: verificar se será necessário
}				t_point;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

typedef struct s_sphere
{
	t_point	center;
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
t_point		set_point(double x, double y, double z);
t_vector	set_vector(double x, double y, double z);
double		vector_length(t_vector vector);
t_vector	add_vectors(t_vector a, t_vector b);
t_vector	subtract_vectors(t_vector a, t_vector b);
t_vector	subtract_points(t_point a, t_point b);
t_point		add_point_and_vector(t_point point, t_vector vector);
t_point		subtract_point_and_vector(t_point point, t_vector vector);
t_vector	negative_vector(t_vector vector);
t_vector	multiply_vector_by_scalar(t_vector vector, double scalar);
t_vector	normalize_vector(t_vector vector);
double		scalar_product(t_vector a, t_vector b);
t_vector	cross_product(t_vector a, t_vector b);

// rays
t_ray	set_ray(t_point origin, t_vector direction);
t_point	ray_position(t_ray ray, double distance);

//elements
t_sphere	*create_sphere(t_point center, double radius, t_color color);
t_intersection	sphere_intersection(t_ray ray, t_sphere sphere);

// close
int		close_minirt(t_mlx *mlx);

// error
int		minirt_error(t_mlx *mlx, char *msg);
void	minirt_malloc_error(char *function);

#endif
