/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:08:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/05 15:59:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_point(t_point *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1.0; // verificar se precisa
}

t_point	*create_point(double x, double y, double z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		minirt_malloc_error("create_point");
	set_point(point, x, y, z);
	return (point);
}

void	set_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = 0.0; // verificar se precisa
}

t_vector	*create_vector(double x, double y, double z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		minirt_malloc_error("create_vector");
	set_vector(vector, x, y, z);
	return (vector);
}

/**
 * @brief
 *
 * @param vector
 * @return double
 */
double	vector_length(t_vector vector)
{
	double	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	return (length);
}
