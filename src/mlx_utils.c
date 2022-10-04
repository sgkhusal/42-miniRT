/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:34 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 23:24:48 by sguilher         ###   ########.fr       */
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

int	put_image_again(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.ptr, 0, 0);
	return (0);
}

static int	key_press(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
		close_minirt(mlx);
	return (0);
}

void	set_mlx_hooks(t_mlx *mlx)
{
	mlx_expose_hook(mlx->window, &put_image_again, mlx);
	mlx_hook(mlx->window, DESTROY_NOTIFY, BUTTON_PRESS_MASK, close_minirt, mlx);
	mlx_hook(mlx->window, KEY_PRESS, KEY_PRESS_MASK, key_press, mlx);
}
