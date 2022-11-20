/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:30:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/20 15:51:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <../libraries/minilibx_linux/mlx.h>

# define HEIGHT 500
# define WIDTH 500

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESCAPE 65307

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

void	create_mlx_window(t_mlx *mlx);
void	create_mlx_image(t_image *img, t_mlx *mlx);
void	set_mlx_hooks(t_mlx *mlx);

#endif
