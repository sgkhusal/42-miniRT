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

static void	init_minirt(t_rt *rt)
{
	rt->world.objects = NULL;
	rt->camera.transform.matrix = NULL;
	rt->camera.inverse.matrix = NULL;
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	**canvas;

	init_minirt(&rt);
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
