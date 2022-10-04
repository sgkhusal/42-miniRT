/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 21:39:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	coloring_image(t_image *img, t_mlx *mlx)
{
	unsigned int	color;
	int				x;
	int				y;

	x = 0;
	y = 0;
	color = 0x0000FF;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			put_pixel_color(img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_image	img;

	// handle_input - check if is valid input and transform_input
	handle_input(argc, &argv[1]);
	create_mlx_window(&mlx);
	create_mlx_image(&img, &mlx);
	// ray tracing algorithm
	// mlx plot and mlx hook
	coloring_image(&img, &mlx);
	put_pixel_color(&img, mlx.width / 2, mlx.height / 2, rgb_to_int(255, 0, 0));
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
