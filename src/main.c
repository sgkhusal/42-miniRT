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

static void	set_pixel_color(t_vector **pixel_color) /* remove */
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
			pixel_color[i][j] = set_vector(x, x, x);
			j++;
		}
		x = x + 0.001;
		i++;
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
	rt.world = default_world();
	set_pixel_color(canvas); /* algoritmo aqui */
	plot_image(&mlx.img, &mlx, canvas);
	free_objects(&rt.world.objects);
	free_canvas(canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
