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

static t_vector	set_pixel_color(t_point ray_origin, int x, int y, t_rt *rt)
{
	t_ray				ray;
	t_vector			ray_direction;
	t_intersection_list	list;
	t_intersection		*hit;
	t_xs				xs;
	t_vector			color;

	hit = NULL;
	color = set_vector(0, 0, 0);
	init_intersection_list(&list);
	ray_direction = set_vector((double)(x - WIDTH / 2) / PPU,
					(double)(-y + HEIGHT / 2) / PPU, 15); //z = posição da tela ou "parede" em relação a camera
	ray = set_ray(ray_origin, normalize_vector(ray_direction));
	xs = sphere_intersection(ray, *(rt->world.objects->shape.sphere));
	if (xs.count == 2)
		add_intersections(xs, rt->world.objects, &list);
	if (list.head)
		hit = get_hit_intersection(list);
	if (hit)
		color = get_sphere_color(ray,
			rt->world.objects->shape.sphere, rt->world.light, hit);
	free_intersection_list(&list); // precisaria dar free antes do outro retorno...
	return (color);
}

// 1m = 100px
void	rendering_rays(t_vector **pixel_color, t_rt *rt)
{
	t_point	ray_origin;
	int		x_mlx;
	int		y_mlx;

	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -5);
	while (y_mlx < HEIGHT)
	{
		while (x_mlx < WIDTH)
		{
			pixel_color[y_mlx][x_mlx] = set_pixel_color(
				ray_origin, x_mlx, y_mlx, rt);
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
	t_vector	**canvas;

	if (handle_input(argc, argv[1], &rt) == ERROR)
		exit (EXIT_FAILURE);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	free_objects(&rt.world.objects); /* remove */
	rt.world = default_world();
	rendering_rays(canvas, &rt);
	plot_image(&mlx.img, &mlx, canvas);
	free_objects(&rt.world.objects);
	free_canvas(canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
