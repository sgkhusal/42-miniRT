/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:39:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 14:10:08 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to print an "Error" message followed by a
 * message passed as parameter and a newline.
 *
 * @param msg message to be printed.
 */
int	print_error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

/**
 * @brief This function is used to print an "Error" message followed by a
 * message passed as parameter and a value specifying where the error occurred,
 * and a newline;
 *
 * @param msg message to be printed.
 * @param str string specifying where the error occurred.
 */
int	print_error_msg2(char *msg, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

/**
 * @brief This function will not only print an error message, but also free the
 * minilibx window and exit the program.
 *
 * @param mlx mlx structure
 * @param msg message to be printed.
 * @return int EXIT_FAILURE
 */
int	minirt_error(t_mlx *mlx, char *msg)
{
	print_error_msg(msg);
	clean_minirt(mlx);
	exit(EXIT_FAILURE);
}

/**
 * @brief TThis function is used to identify a malloc error and print the name
 * of the function where the error occurred.
 *
 * @param function name of the function where the error occurred.
 */
void	minirt_malloc_error(char *function)
{
	ft_putstr_fd("Error\nmalloc failed at ", 2);
	ft_putstr_fd(function, 2);
	ft_putstr_fd(" function\n", 2);
	exit(EXIT_FAILURE);
}
