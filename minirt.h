/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:59:26 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/04 00:04:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libraries/libft/libft.h"
# include <stdio.h> // printf
# include <math.h>

# include "mlx_utils.h"

typedef union u_color
{
	int		color;
	char	rgb[4];
}				t_color;

// input
void	handle_input(int argc, char *input[]);

// colors
int		rgb_to_int(short int red, short int green, short int blue);

// close
int		close_minirt(t_mlx *mlx);

// error
int		minirt_error(t_mlx *mlx, char *msg);

#endif
