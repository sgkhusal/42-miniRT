/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:45:51 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 12:26:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	set_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0; // verificar se precisa
	return (point);
}

t_vector	subtract_points(t_point a, t_point b)
{
	t_vector	sub;
	double		x;
	double		y;
	double		z;

	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	sub = set_vector(x, y, z);
	return (sub);
}
