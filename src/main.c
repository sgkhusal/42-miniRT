/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 19:04:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_mlx_window(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
	{
		printf("Error\nmlx_init error\n");
		exit(EXIT_FAILURE);
	}
	mlx->width = 500;
	mlx->height = 500;
	mlx->window = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "miniRT");
	if (mlx->window == NULL)
	{
		printf("Error\nmlx_new_window error\n");
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

void	create_mlx_image(t_mlx *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (mlx->img.ptr == NULL)
	{
		printf("Error\nmlx error creating mlx->img.ptr\n");
		free(mlx->window);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
			&mlx->img.line_size, &mlx->img.endian);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	// handle_input - check if is valid input and transform_input
	handle_input(argc, &argv[1]);
	create_mlx_window(&mlx);
	create_mlx_image(&mlx);
	// ray tracing algorithm
	// mlx plot and mlx hook
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
