/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/11 19:52:441 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <stdio.h> // printf
# include <math.h>
# include <stdbool.h>

# include "mlx_utils.h"
# include "matrix.h"
# include "tuples.h"

enum e_objects
{
	SPHERE,
	PLANE,
	CYLINDER
};

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
typedef struct s_xs
{
	double	t1;
	double	t2;
	int		count;
}				t_xs;

/* * se hit < 0, a interseção é atrás da câmera
 * se hit = 0, a interseção é na câmera
 * se hit > 0, a interseção é na frente da câmera
 * a intersecção visível é a menor intersecção positiva
 */
typedef struct s_intersection
{
	double					t;
	int						object;
	//double					hit;
	struct s_intersection	*next;
}				t_intersection;

typedef struct intersection_list
{
	t_intersection	*intersection;
	int				total;
}				t_intersection_list;

typedef struct s_rt
{
	t_intersection_list	*intersections;
}				t_rt;

// input
void			handle_input(int argc, char *input[]);

// intersections
t_intersection	*create_intersection(double t, int object);

// colors
int				rgb_to_int(short int red, short int green, short int blue);
t_color			set_color(short int red, short int green, short int blue);

// rays
t_ray			set_ray(t_point origin, t_vector direction);
t_point			ray_position(t_ray ray, double distance);

//elements
t_sphere		*create_sphere(t_point center, double radius, t_color color);
t_xs			sphere_intersection(t_ray ray, t_sphere sphere);
double			get_hit(double t1, double t2);

// close
int				close_minirt(t_mlx *mlx);

// error
int				minirt_error(t_mlx *mlx, char *msg);
void			minirt_malloc_error(char *function);

#endif
