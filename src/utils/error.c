/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:39:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:39:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
