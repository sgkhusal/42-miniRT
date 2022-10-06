/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:59:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 11:56:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	add_vectors(t_vector a, t_vector b)
{
	t_vector	sum;
	double		x;
	double		y;
	double		z;

	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
	sum = set_vector(x, y, z);
	return (sum);
}

t_vector	subtract_vectors(t_vector a, t_vector b)
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

t_vector	multiply_vector_by_scalar(t_vector vector, double scalar)
{
	t_vector	product;
	double		x;
	double		y;
	double		z;

	x = vector.x * scalar;
	y = vector.y * scalar;
	z = vector.z * scalar;
	product = set_vector(x, y, z);
	return (product);
}

double	scalar_product(t_vector a, t_vector b)
{
	double	scalar;

	scalar = a.x * b.x
		+ a.y * b.y
		+ a.z * b.z;
	return (scalar);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	double	x;
	double	y;
	double	z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	return (set_vector(x, y, z));
}
