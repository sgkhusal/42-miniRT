/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:59:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 13:48:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to add two vectors.
 *
 * @param a first vector to be added
 * @param b second vector to be added
 * @return t_vector resulting vector
 */
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

/**
 * @brief This function is used to subtract two vectors. It's like adding a vector
 * with the opposite direction.
 *
 * @param a first vector
 * @param b vector to be subtracted from the first vector
 * @return t_vector resulting vector
 */
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

/**
 * @brief This function is used to multiply a vector by a scalar. A scalar is a
 * single number that is multiplied by each component of the vector. It is
 * useful to scale a vector while keeping its direction.
 *
 * @param vector vector to be multiplied by the scalar
 * @param scalar scalar to be multiplied
 * @return t_vector resulting vector
 */
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

/**
 * @brief The scalar product is also known as the dot product. It is used while
 * intersecting a ray with an object or calculating shading. The scalar product
 * takes two vectors and returns a scalar. The scalar product of two vectors is
 * the sum of the products of their corresponding components.
 * The smaller the scalar product, the larger the angle between the vectors.
 *
 * @param a first vector
 * @param b second vector
 * @return double scalar product
 */
double	scalar_product(t_vector a, t_vector b)
{
	double	scalar;

	scalar = a.x * b.x
		+ a.y * b.y
		+ a.z * b.z;
	return (scalar);
}

/**
 * @brief With cross product, we can find a vector that is perpendicular to the
 * two vectors we are multiplying. It is used to calculate the normal vector of a
 * plane. Order matters when calculating the cross product.
 *
 * @param a first vector
 * @param b second vector
 * @return t_vector resulting vector
 */
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
