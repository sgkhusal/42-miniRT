/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:26:39 by sguilher         ###   ########.fr       */
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

int	print_error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

int	print_error_msg2(char *msg, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

int	minirt_error(t_mlx *mlx, char *msg)
{
	print_error_msg(msg);
	clean_minirt(mlx);
	exit(EXIT_FAILURE);
}

void	minirt_malloc_error(char *function)
{
	ft_putstr_fd("Error\nmalloc failed at ", 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd(" function\n", 2);
	exit(EXIT_FAILURE);
}

int	check_double_values(double a, double b)
{
	if (fabs(a - b) < 0.00001)
		return (TRUE);
	return (FALSE);
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
