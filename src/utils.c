/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 23:14:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_minirt(t_mlx *mlx)
{
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->ptr, mlx->window);
	if (mlx->ptr != NULL)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

int	close_minirt(t_mlx *mlx)
{
	clean_minirt(mlx);
	exit(EXIT_SUCCESS);
}

int	minirt_error(t_mlx *mlx, char *msg)
{
	printf("Error\n%s\n", msg);
	clean_minirt(mlx);
	exit(EXIT_FAILURE);
}
