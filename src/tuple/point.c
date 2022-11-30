/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:45:51 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 12:01:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will set the values of each coordinate of a point.
 * The values are passed as parameters except for the w coordinate, which is
 * always set to 1., in order to represent a point.
 *
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 * @return t_point resulting point
 */
t_point	set_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

/**
 * @brief This function is used to subtract two points. The result is a vector.
 * The vector points from the second point to the first point. It will be used
 * to calculate the vector pointing to the light source from the intersection
 * point.
 *
 * @param a first point
 * @param b second point
 * @return t_vector vector pointing from b to a
 */
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
