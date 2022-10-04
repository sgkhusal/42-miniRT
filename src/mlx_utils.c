/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:34 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 21:21:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_mlx_window(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
	{
		printf("Error\nmlx error initializing mlx\n");
		exit(EXIT_FAILURE);
	}
	mlx->width = 500;
	mlx->height = 500;
	mlx->window = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "miniRT");
	if (mlx->window == NULL)
	{
		printf("Error\nmlx error creating window\n");
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

void	create_mlx_image(t_image *img, t_mlx *mlx)
{
	img->ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (img->ptr == NULL)
	{
		printf("Error\nmlx error creating image\n");
		free(mlx->window);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
}
