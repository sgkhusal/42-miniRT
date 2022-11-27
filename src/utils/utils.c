/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 18:11:24 by sguilher         ###   ########.fr       */
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

t_bool	check_equal_points(t_point a, t_point b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
}

t_bool	check_double_values(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

t_bool	check_equal_vectors(t_vector a, t_vector b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
