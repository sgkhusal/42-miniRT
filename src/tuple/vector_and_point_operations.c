/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_and_point_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:51:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 12:10:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to add a point and a vector. It can be used to
 * know the resulting points after following a vector from a starting point.
 *
 * @param point starting point
 * @param vector vector to be added
 * @return t_point resulting point
 */
t_point	add_point_and_vector(t_point point, t_vector vector)
{
	t_point	sum;
	double	x;
	double	y;
	double	z;

	x = point.x + vector.x;
	y = point.y + vector.y;
	z = point.z + vector.z;
	sum = set_point(x, y, z);
	return (sum);
}

/**
 * @brief This function is used to subtract a vector from a point. It's like
 * adding a vector with the opposite direction. It can be used to know the
 * resulting point after following a vector in the opposite direction from a
 * starting point.
 *
 * @param point starting point
 * @param vector vector to be subtracted
* @return t_point resulting point
 */
t_point	subtract_point_and_vector(t_point point, t_vector vector)
{
	t_point	sub;
	double	x;
	double	y;
	double	z;

	x = point.x - vector.x;
	y = point.y - vector.y;
	z = point.z - vector.z;
	sub = set_point(x, y, z);
	return (sub);
}
