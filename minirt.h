/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 21:40:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <./libraries/minilibx_linux/mlx.h> // minilibx
# include <stdio.h> // printf

# define HEIGHT 1000
# define WIDTH 1000

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

#endif
