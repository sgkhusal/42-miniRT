/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:59:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/26 19:02:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	plot_image(t_image *img, t_mlx *mlx, t_vector **canvas)
{
	t_color		color;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			color = transform_vector_to_color(canvas[y][x]);
			put_pixel_color(img, x, y, color.color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.ptr, 0, 0);
}

