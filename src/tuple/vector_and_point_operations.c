/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_and_point_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:51:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 22:00:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	add_point_and_vector(t_point point, t_vector vector)
{
	t_point	sum;
	double	x;
	double	y;
	double	z;

	x = point.x + vector.x;
	y = point.y + vector.y;
	z = point.z + vector.z;
	sum = create_point(x, y, z);
	return (sum);
}

t_point	subtract_point_and_vector(t_point point, t_vector vector)
{
	t_point	sub;
	double	x;
	double	y;
	double	z;

	x = point.x - vector.x;
	y = point.y - vector.y;
	z = point.z - vector.z;
	sub = create_point(x, y, z);
	return (sub);
}
