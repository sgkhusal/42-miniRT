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

t_vector	**create_canvas()
{
	t_vector	**canvas;
	int			i;
	int			j;

	canvas = malloc(sizeof(t_vector *) * HEIGHT);
	if (!canvas)
		minirt_malloc_error("create_canvas");
	i = 0;
	while (i < HEIGHT)
	{
		canvas[i] = malloc(sizeof(t_vector) * WIDTH);
		if (!canvas[i])
			minirt_malloc_error("create_canvas");
		j = 0;
		while (j < WIDTH)
		{
			canvas[i][j] = set_vector(0, 0, 0);
			j++;
		}
		i++;
	}
	return (canvas);
}

void	free_canvas(t_vector **canvas)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(canvas[i]);
		i++;
	}
	free(canvas);
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

void	rendering_rays(t_vector **pixel_color)
{
	t_ray		ray;
	int		x_mlx; // 0 - 500
	int		y_mlx; // 0 - 500
	t_point		ray_origin;
	t_vector	ray_direction;
	t_sphere	*s;
	//t_color	color;
	t_vector	color;
	t_intersection_list	list;
	t_intersection		*intersection;

	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -3);
	s = create_sphere();
	color = normalize_color(set_color(255, 0, 0));
	//color = set_color(255, 0, 0);
	/* t_matrix translation;
	translation = translation_matrix(0, 1, 0);
	set_transform(s, translation); */
	/* t_matrix scaling;
	scaling = scaling_matrix(2, 2, 2);
	set_transform(s, (scaling)); */
	//set_transform(s, multiply_matrix(translation, scaling));
	init_intersection_list(&list);
	intersection = NULL;
	while (y_mlx <= HEIGHT)
	{
		while (x_mlx <= WIDTH)
		{
			// 1m = 100px
			// z = 1 para o cálculo da direção do raio - (0, 0 , -3)
			//ray = set_ray(ray_origin, set_vector((x_mlx - WIDTH / 2) / 100, (-y_mlx + HEIGHT / 2)/100, 0));
			ray_direction = set_vector((double)(x_mlx - 250)/100, (double)(-y_mlx + 250)/100, 1);
			//printf("ray direction: %f %f %f\n", ray_direction.x, ray_direction.y, ray_direction.z);
			ray = set_ray(ray_origin, ray_direction);
			sphere_intersection(ray, *s, &list);
			if (list.head)
				intersection = get_hit_intersection(list);
			if (intersection)
			{
				//if (x_mlx == 250 && y_mlx == 250)
					//printf("intersection in x = %d, y = %d - t = %f\n", x_mlx, y_mlx, intersection->t);
				pixel_color[y_mlx][x_mlx] = color;
				//put_pixel_color(&mlx->img, x_mlx, y_mlx, color.color);
				//mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.ptr, 0, 0);
			}
			/* else
				pixel_color[y_mlx][x_mlx] = set_vector(0, 0, 0); */
			free_intersection_list(&list);
			intersection = NULL;
			x_mlx++;
		}
		x_mlx = 0;
		y_mlx++;
	}
	free_sphere(s);
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	**canvas;

	if (handle_input(argc, argv[1], &rt) == ERROR)
		exit (EXIT_FAILURE);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	//set_canvas(canvas);
	//plot_image(&mlx.img, &mlx, canvas);
	rendering_rays(canvas);
	plot_image(&mlx.img, &mlx, canvas);
	free_objects(&rt.objects); // precisa ser colocado dentro da função da mlx
	free_canvas(canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
