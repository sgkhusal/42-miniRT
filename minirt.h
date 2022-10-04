/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 22:18:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <./libraries/minilibx_linux/mlx.h> // minilibx
# include <stdio.h> // printf

# define HEIGHT 255
# define WIDTH 1000

# define DESTROY_NOTIFY 29 // DestroyNotify
# define NO_EVENT_MASK 0L // NoEventMask

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		width;
	int		height;
	t_image	img;
}				t_mlx;

typedef union u_color
{
	int		color;
	char	rgb[4];
}				t_color;


// input
void	handle_input(int argc, char *input[]);

// mlx
void	create_mlx_window(t_mlx *mlx);
void	create_mlx_image(t_image *img, t_mlx *mlx);

// colors
int		rgb_to_int(short int red, short int green, short int blue);

// close
int		close_minirt(t_mlx *mlx);

// error
int		minirt_error(t_mlx *mlx, char *msg);

#endif
