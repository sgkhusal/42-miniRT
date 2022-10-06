/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:51:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 18:41:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*add_vectors(t_vector a, t_vector b)
{
	t_vector	*sum;
	double	x;
	double	y;
	double	z;

	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
	sum = create_vector(x, y, z);
	return (sum);
}

t_point	*add_point_and_vector(t_point point, t_vector vector)
{
	t_point	*sum;
	double	x;
	double	y;
	double	z;

	x = point.x + vector.x;
	y = point.y + vector.y;
	z = point.z + vector.z;
	sum = create_point(x, y, z);
	return (sum);
}

t_vector	*subtract_vectors(t_vector a, t_vector b)
{
	t_vector	*sub;
	double	x;
	double	y;
	double	z;

	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	sub = create_vector(x, y, z);
	return (sub);
}

t_vector	*subtract_points(t_point a, t_point b)
{
	t_vector	*sub;
	double	x;
	double	y;
	double	z;

	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	sub = create_vector(x, y, z);
	return (sub);
}

t_point	*subtract_point_and_vector(t_point point, t_vector vector)
{
	t_point	*sub;
	double	x;
	double	y;
	double	z;

	x = point.x - vector.x;
	y = point.y - vector.y;
	z = point.z - vector.z;
	sub = create_point(x, y, z);
	return (sub);
}

t_vector	*negative_vector(t_vector vector)
{
	return (create_vector(-vector.x, -vector.y, -vector.z));
}

t_vector	*multiply_vector_by_scalar(t_vector vector, double scalar)
{
	t_vector	*product;
	double	x;
	double	y;
	double	z;

	x = vector.x * scalar;
	y = vector.y * scalar;
	z = vector.z * scalar;
	product = create_vector(x, y, z);
	return (product);
}

t_vector	*normalize_vector(t_vector vector)
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

double	scalar_product(t_vector a, t_vector b)
{
	double	scalar;

	scalar = a.x * b.x
		+ a.y * b.y
		+ a.z * b.z;
	return (scalar);
}

t_vector	*cross_product(t_vector a, t_vector b)
{
	double	x;
	double	y;
	double	z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	return (create_vector(x, y, z));
}
