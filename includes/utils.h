/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:54:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/11 23:10:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./libraries/libft/libft.h"
# include "mlx_utils.h"
# include "tuples.h"
# include "matrix.h"

# define AMBIENT_LIGHT 'A'
# define CAMERA 'C'
# define LIGHT 'L'
# define FILE_PLANE 'pl'
# define FILE_SPHERE 'sp'
# define FILE_CYLINDER 'cy'

# define EPSILON 0.00001

enum e_status
{
	OK,
	ERROR
};

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}				t_bhaskara;

typedef union u_color
{
	int		color;
	char	rgb[4];
}				t_color;

// colors
int			rgb_to_int(short int red, short int green, short int blue);
t_color		set_color(short int red, short int green, short int blue);
t_color		transform_vector_to_color(t_vector color);
t_vector	multiply_colors(t_vector a, t_vector b);
t_vector	normalize_color(t_color color);
t_vector	**create_canvas(void);
void		free_canvas(t_vector **canvas);
void		plot_image(t_image *img, t_mlx *mlx, t_vector **canvas);

// input utils
int			total_infos(char **infos);
int			validate_double_chars(char *str);
int			validate_color_chars(char *str);
int			validate_coordinates_chars(char *str);
int			validate_nb_chars(char *str);
t_color		transform_color(char *rgb_str, int *status);
double		transform_ratio(char *ratio_str, int *status);
t_point		transform_coordinates(char *xyz_str, int *status);
t_vector	transform_orientation(char *xyz_str, int *status);
double		transform_double(char *str, int *status);
int			transform_fov(char *fov_str, int *status);

// close
int			close_minirt(t_mlx *mlx);

// utils
int			check_double_values(double a, double b);
double		ft_atod(char *nb);

// error
int			print_error_msg(char *msg);
int			print_error_msg2(char *msg, char *str);
int			minirt_error(t_mlx *mlx, char *msg);
void		minirt_malloc_error(char *function);

// clean
void		free_array(char **arr);
void		clean_minirt(t_mlx *mlx);

#endif
