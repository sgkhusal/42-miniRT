/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 19:04:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <./libraries/minilibx_linux/mlx.h> // minilibx
# include <stdio.h> // printf

# define HEIGHT 1000
# define WIDTH 500

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

void	handle_input(int argc, char *input[]);

#endif
