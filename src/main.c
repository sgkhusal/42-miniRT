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

void	coloring_image(t_image *img, t_mlx *mlx)
{
	unsigned int	color;
	int				x;
	int				y;

	x = 0;
	y = 0;
	color = 0x000000;
	while (y < mlx->height)
	{
		while (x < mlx->width)
		{
			put_pixel_color(img, x, y, color);
			x++;
		}
		color++;
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

void	sphere_test(void)
{
	t_intersection	*intersection;
	t_sphere		*sphere;
	t_ray			ray;

	sphere = create_sphere(set_point(4, 3, 0), 1, set_color(255, 0, 0));
	ray = set_ray(set_point(0, 0, 0), set_vector(1, 1, 0));
	intersection = sphere_intersection(ray, *sphere);
	printf("hit: %f\nt1: %f\nt2: %f\n", intersection->hit, intersection->t1,
		intersection->t2);
	free(sphere);
	free(intersection);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	// handle_input - check if is valid input and transform_input
	handle_input(argc, &argv[1]);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	// ray tracing algorithm
	// mlx plot and mlx hook
	coloring_image(&mlx.img, &mlx);
	put_pixel_color(&mlx.img, mlx.width / 2, mlx.height / 2, rgb_to_int(255, 0, 0));
	put_circle(&mlx, 50.5, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	set_mlx_hooks(&mlx);
	sphere_test();
	mlx_loop(mlx.ptr);
	return (0);
}
