/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:33:12 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/26 17:34:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_circle(t_mlx *mlx, double radius, double center_x, double center_y)
{
	double	teta;
	double	x;
	double	y;
	int		color;

	color = rgb_to_int(0, 255, 0);
	teta = 0;
	while (teta < 360)
	{
		x = center_x + radius * cos(teta);
		y = center_y + radius * sin(teta);
		put_pixel_color(&mlx->img, x, y, color);
		teta += 0.1;
	}
}
