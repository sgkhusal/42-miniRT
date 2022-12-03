/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:22:11 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 14:25:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will destroy the mlx image, window and display and free
 * the mlx ptr, clearing the memory.
 *
 * @param mlx mlx structure
 */
void	clean_mlx(t_mlx *mlx)
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

/**
 * @brief This function will clean the mlx structure, freeing the allocated
 * memory and destroying the mlx image, window and display (if it exists).
 * It will also exit the program with EXIT_SUCCESS status.
 *
 * @param mlx mlx structure
 * @return int EXIT_SUCCESS
 */
int	close_minirt(t_mlx *mlx)
{
	clean_mlx(mlx);
	exit(EXIT_SUCCESS);
}

/**
 * @brief This function will free the allocated memory of a list of objects.
 * It will free the memory of each object and the list itself (if it exists).
 *
 * @param arr the array to be freed
 */
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
