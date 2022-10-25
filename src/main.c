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

void	rendering_rays(t_mlx *mlx)
{
	t_ray		ray;
	//t_vector	pixel_color[500][500];
	int			x_mlx; // 0 - 500
	int			y_mlx; // 0 - 500
	t_point		ray_origin;
	t_sphere	*s;
	t_color		color;
	t_intersection_list	list;
	t_intersection		*intersection;

	// z = 1 para o cálculo da direção do raio - (0, 0 , -3)
	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -3);
	s = create_sphere();
	//set_transform(s, t_matrix transform);
	color = set_color(255, 0, 0);
	intersection = NULL;
	t_matrix translation;
	t_matrix scaling;
	translation = translation_matrix(0, 0, -3);
	scaling = scaling_matrix(100, 100, 100);
	set_transform(s, multiply_matrix(translation, scaling));
	while (y_mlx < mlx->height)
	{
		while (x_mlx < mlx->width)
		{
			//pixel_color = transform_vector_to_color(pixel_color[y][x]);
			//put_pixel_color(mlx, x, y, color.color);
			ray = set_ray(ray_origin, set_vector(x_mlx + 250, -y_mlx + 250, 0));
			sphere_intersection(ray, *s, &list);
			if (list.head)
				intersection = get_hit_intersection(list);
			if (intersection)
			{
				printf("intersection in x = %d, y = %d - t = %f\n", x_mlx, y_mlx, list.head->t);
				put_pixel_color(&mlx->img, x_mlx, y_mlx, color.color);
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.ptr, 0, 0);
			}
			// verifica se tem algum t e usa get_hit
			// seta o pixel_color com a cor do elemento
			x_mlx++;
		}
		x_mlx = 0;
		y_mlx++;
	}
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	pixel_color[500][500];

	if (handle_input(argc, argv[1], &rt) == ERROR)
		exit (EXIT_FAILURE);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	set_pixel_color(pixel_color);
	t_matrix translation;
	t_matrix scaling;
	t_matrix m1;
	t_matrix m2;
	translation = translation_matrix(0, 0, 3);
	scaling = scaling_matrix(100, 100, 100);
	m1 = multiply_matrix(translation, scaling);
	m2 = multiply_matrix(scaling, translation);
	print_matrix(m1);
	print_matrix(m2);
	plot_image(&mlx.img, &mlx, pixel_color);
	/* put_pixel_color(&mlx.img, mlx.width / 2, mlx.height / 2,
		rgb_to_int(255, 0, 0));
	put_circle(&mlx, 50.5, WIDTH / 2, HEIGHT / 2); */
	rendering_rays(&mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	free_objects(&rt.objects); // precisa ser colocado dentro da função da mlx
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
