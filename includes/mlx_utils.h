/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:30:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 10:45:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>

/* defines windown size */
# define HEIGHT 700
# define WIDTH 1000

/* defines key codes for mlx_key_hook */
# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESCAPE 65307

/**
 * @brief struct to store mlx image variables
 */
typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_image;

/**
 * @brief struct to store mlx window variables
 */
typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		width;
	int		height;
	t_image	img;
}				t_mlx;

/* mlx functions */
void	create_mlx_window(t_mlx *mlx);
void	create_mlx_image(t_image *img, t_mlx *mlx);
void	set_mlx_hooks(t_mlx *mlx);

#endif
