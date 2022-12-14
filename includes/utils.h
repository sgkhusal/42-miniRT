/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:54:24 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 11:03:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./libraries/libft/libft.h"
# include "mlx_utils.h"
# include "tuples.h"
# include "matrix.h"

/* defines input elements */
# define AMBIENT_LIGHT 'A'
# define CAMERA 'C'
# define LIGHT 'L'

/* defines renderizable elements to be called while testing */
# define FILE_PLANE 'pl'
# define FILE_SPHERE 'sp'
# define FILE_CYLINDER 'cy'

/*EPSILON is the minimum value for a double to be considered different from 0 */
# define EPSILON 0.00001

/**
 * @brief enum to check whether the function was successful or
 * encountered an error
 */
enum e_status
{
	OK,
	ERROR
};

/**
 * @brief enum for boolean values
 */
typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

/**
 * @brief auxiliary struct to store each element of the
 * bhaskara formula
 */
typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}				t_bhaskara;

/**
 * @brief union to store the color in rgb format as well as in int format
 */
typedef union u_color
{
	int		color;
	char	rgb[4];
}				t_color;

/* color utils functions */
t_color		transform_vector_to_color(t_vector color);
t_vector	multiply_colors(t_vector a, t_vector b);
t_vector	normalize_color(double red, double green, double blue);
t_vector	**create_canvas(void);
void		free_canvas(t_vector **canvas);
void		plot_image(t_image *img, t_mlx *mlx, t_vector **canvas);

/* input utils functions */
int			total_infos(char **infos);
int			validate_double_chars(char *str);
int			validate_color_chars(char *str);
int			validate_coordinates_chars(char *str);
int			validate_nb_chars(char *str);
t_vector	transform_color(char *rgb_str, int *status);
double		transform_ratio(char *ratio_str, int *status);
t_point		transform_coordinates(char *xyz_str, int *status);
t_vector	transform_orientation(char *xyz_str, int *status);
double		transform_double(char *str, int *status);
int			transform_fov(char *fov_str, int *status);
t_matrix	get_rotation_matrix(t_vector orientation);
char		**parse_input(char *line, char c, int size_expected, int *status);
double		ft_atod(char *nb);

/* close functions */
int			close_minirt(t_mlx *mlx);

/* utils functions */
t_bool		check_double_values(double a, double b);
t_bool		check_equal_points(t_point a, t_point b);;
t_bool		check_equal_vectors(t_vector a, t_vector b);

/* error functions */
int			print_error_msg(char *msg);
int			print_error_msg2(char *msg, char *str);
int			minirt_error(t_mlx *mlx, char *msg);
void		minirt_malloc_error(char *function);

/* clean functions */
void		free_array(char **arr);
void		clean_mlx(t_mlx *mlx);

#endif
