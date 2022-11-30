/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:59:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 14:32:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to plot a pixel in the canvas given its
 * coordinates and color.
 *
 * @param img the image structure
 * @param x x coordinate of the pixel
 * @param y y coordinate of the pixel
 * @param color color of the pixel
 */
static void	put_pixel_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

/**
 * @brief This function is used to plot the whole image in the mlx window.
 * It will transform the color vector into an integer color and plot it
 * using the put_pixel_color function and the mlx_put_image_to_window function.
 *
 * @param img the image structure
 * @param mlx the mlx structure
 * @param canvas the canvas
 */
void	plot_image(t_image *img, t_mlx *mlx, t_vector **canvas)
{
	t_color		color;
	int			x;
	int			y;

	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			color = transform_vector_to_color(canvas[y][x]);
			put_pixel_color(img, x, y, color.color);
			if (y == mlx->height / 2) /* remove if-else - red cross*/
				put_pixel_color(img, x, y, 0xFF0000);
			else if (x == mlx->width / 2)
				put_pixel_color(img, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.ptr, 0, 0);
}
