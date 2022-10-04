/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:34 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 22:27:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_mlx_window(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->window = NULL;
	mlx->img.ptr = NULL;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		minirt_error(mlx, "mlx error initializing mlx");
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->window = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "miniRT");
	if (mlx->window == NULL)
		minirt_error(mlx, "mlx error creating window");
}

void	create_mlx_image(t_image *img, t_mlx *mlx)
{
	img->ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (img->ptr == NULL)
		minirt_error(mlx, "mlx error creating image");
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
}
