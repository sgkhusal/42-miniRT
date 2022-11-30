/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 14:29:22 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will destroy the mlx image, window and display and free
 * the mlx ptr, clearing the memory.
 *
 * @param mlx mlx structure
 */
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
	clean_minirt(mlx);
	exit(EXIT_SUCCESS);
}

/**
 * @brief This function is an auxiliary function to compare two different
 * points. It will check each coordinate and return 1 if they are equal, or 0
 * if they are different.
 *
 * @param a point a
 * @param b point b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_equal_points(t_point a, t_point b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
}

/**
 * @brief This is an auxiliary function to check if two double values are
 * equal. It will check if the difference between the two values is less than
 * the epsilon value.
 *
 * @param a double a
 * @param b double b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_double_values(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

/**
 * @brief This function will compare two vectors. It will check each coordinate
 * and return 1 if they are equal, or 0 if they are different.
 *
 * @param a vector a
 * @param b vector b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_equal_vectors(t_vector a, t_vector b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
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
