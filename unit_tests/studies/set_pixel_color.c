/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:34:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/26 17:54:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* void	set_pixel_color(t_vector **pixel_color)
{
	int				i;
	int				j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_color[i][j] = set_vector(1, 1, 1); // lightning
			j++;
		}
		i++;
	}
} */

void	set_pixel_color(t_vector **pixel_color)
{
	int				i;
	int				j;
	double			x;

	i = 0;
	x = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_color[i][j] = set_vector(x, x, x);
			j++;
		}
		x = x + 0.002;
		i++;
	}
}
