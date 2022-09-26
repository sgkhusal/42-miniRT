/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/09/22 19:08:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	// handle_input - check if is valid input and transform_input
	if (argc != 2)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("file name = %s\n", argv[1]);
	// ray tracing algorithm
	// mlx plot and mlx hook
	mlx.ptr = NULL;
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
	{
		printf("Mlx init error");
		exit(EXIT_FAILURE);
	}
	mlx.width = 500;
	mlx.height = 500;
	mlx.window = mlx_new_window(mlx.ptr, mlx.width, mlx.height, "miniRT");
	if (mlx.window == NULL)
	{
		printf("Mlx window error");
		free(mlx.ptr);
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx.ptr);
	return (0);
}
