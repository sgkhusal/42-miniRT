/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:08:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/05 22:01:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	create_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0; // verificar se precisa
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

t_vector	normalize_vector(t_vector vector)
{
	double	length;
	double	x;
	double	y;
	double	z;

	length = vector_length(vector);
	x = vector.x / length;
	y = vector.y / length;
	z = vector.z / length;
	return (create_vector(x, y, z));
}

t_vector	negative_vector(t_vector vector)
{
	return (create_vector(-vector.x, -vector.y, -vector.z));
}
