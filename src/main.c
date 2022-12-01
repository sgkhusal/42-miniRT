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

/**
 * @brief Initializes the t_rt main struct.
 * 
 * @param rt t_rt struct to be initialized.
 */
static void	init_minirt(t_rt *rt)
{
	rt->world.objects = NULL;
	rt->camera.transform.matrix = NULL;
	rt->camera.inverse.matrix = NULL;
}

/**
 * @brief The main function of the program. Initializes the t_rt struct and
 * calls the functions to parse the scene file and render the image. Then,
 * it frees the allocated memory and keeps the program running until the
 * user closes the window.
 * 
 * @param argc number of arguments passed to the program.
 * @param argv array of arguments passed to the program.
 * @return int 0 if the program runs successfully.
 */
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
