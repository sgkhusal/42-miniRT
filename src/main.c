/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 15:170 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel_color(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

// criação de raios
// joga o raio nos elementos
// função de lightning
// retorna a cor do pixel

/* void	set_pixel_color(t_vector pixel_color[500][500])
{
	int				i;
	int				j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_color[i][j] = set_vector(1, 1, 1); // lightning
			j++;
		}
		i++;
	}
} */

void	set_pixel_color(t_vector pixel_color[500][500])
{
	int				i;
	int				j;
	double			x;

	i = 0;
	x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_color[i][j] = set_vector(x, x, x); // lightning
			j++;
		}
		x = x + 0.002;
		i++;
	}
}

void	plot_image(t_image *img, t_mlx *mlx, t_vector pixel_color[500][500])
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
			color = transform_vector_to_color(pixel_color[y][x]);
			put_pixel_color(img, x, y, color.color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_circle(t_mlx *mlx, double radius, double center_x, double center_y)
{
	double	teta;
	double	x;
	double	y;
	int		color;

	color = rgb_to_int(0, 255, 0);
	teta = 0;
	while (teta < 360)
	{
		x = center_x + radius * cos(teta);
		y = center_y + radius * sin(teta);
		put_pixel_color(&mlx->img, x, y, color);
		teta += 0.1;
	}
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	pixel_color[500][500];

	rt = handle_input(argc, argv[1]);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	set_pixel_color(pixel_color);
	plot_image(&mlx.img, &mlx, pixel_color);
	/* put_pixel_color(&mlx.img, mlx.width / 2, mlx.height / 2,
		rgb_to_int(255, 0, 0));
	put_circle(&mlx, 50.5, WIDTH / 2, HEIGHT / 2); */
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	printf("oi: %d", rt.camera.oi);
	return (0);
}
