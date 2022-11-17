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

// 1m = 100px
void	rendering_rays(t_vector **pixel_color, t_rt *rt)
{
	t_ray	ray;
	int		x_mlx;
	int		y_mlx;

	x_mlx = 0;
	y_mlx = 0;
	ray.origin = set_point(0, 0, -5);
	while (y_mlx < HEIGHT)
	{
		while (x_mlx < WIDTH)
		{
			ray.direction = normalize_vector(set_vector((double)(x_mlx - WIDTH / 2) / PPU,
					(double)(-y_mlx + HEIGHT / 2) / PPU, 15));
			pixel_color[y_mlx][x_mlx] = color_at(rt->world, ray);
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
	render(rt.camera, rt.world, canvas, &mlx);
	free_objects(&rt.world.objects);
	free_canvas(canvas);
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
