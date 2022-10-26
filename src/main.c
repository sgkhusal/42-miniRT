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

// 1m = 200px
void	rendering_rays(t_vector **pixel_color)
{
	t_ray				ray;
	int					x_mlx; // 0 - 500
	int					y_mlx; // 0 - 500
	t_point				ray_origin;
	t_vector			ray_direction;
	t_sphere			*s;
	t_vector			color;
	t_intersection_list	list;
	t_intersection		*intersection;

	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -5);
	s = create_sphere();
	color = normalize_color(set_color(255, 0, 0));
	/* t_matrix translation;
	translation = translation_matrix(2, 1, 0);
	//set_transform(s, translation);
	t_matrix scaling;
	scaling = scaling_matrix(2, 2, 2); */
	//set_transform(s, (scaling));
	/* set_transform(s, multiply_matrix(translation, scaling));
	free_matrix(translation);
	free_matrix(scaling); */
	init_intersection_list(&list);
	intersection = NULL;
	while (y_mlx < HEIGHT)
	{
		while (x_mlx < WIDTH)
		{
			ray_direction = set_vector((double)(x_mlx - WIDTH / 2)/100,
				(double)(-y_mlx + HEIGHT / 2)/100, 15); //z = posição da tela ou "parede" em relação a camera
			//printf("ray direction: %f %f %f\n", ray_direction.x, ray_direction.y, ray_direction.z);
			ray = set_ray(ray_origin, ray_direction);
			sphere_intersection(ray, *s, &list);
			if (list.head)
				intersection = get_hit_intersection(list);
			if (intersection)
			{
				//printf("intersection in x = %d, y = %d - t = %f\n", x_mlx, y_mlx, intersection->t);
				pixel_color[y_mlx][x_mlx] = color;
			}
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
	rendering_rays(canvas);
	plot_image(&mlx.img, &mlx, canvas);
	free_objects(&rt.objects); // precisa ser colocado dentro da função da mlx
	free_canvas(canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
