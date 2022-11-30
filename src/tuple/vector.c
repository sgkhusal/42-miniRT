/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:08:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/30 12:04:30 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will set the values of each coordinate of a vector.
 * The values are passed as parameters except for the w coordinate, which is
 * always set to 0., in order to represent a vector.
 *
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 * @return t_vector resulting vector
 */
t_vector	set_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;
	return (vector);
}

/**
 * @brief This function will calculate the magnitude of a vector. It’s how
 * far you would travel in a straight line if you were to walk from one end of
 * the vector to the other.
 *
 * @param vector the vector to calculate the magnitude of
 * @return double the length of the vector
 */
double	vector_length(t_vector vector)
{
	double	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	return (length);
}

/**
 * @brief Normalization is the process of dividing a vector by its magnitude.
 * This will result in a vector with the same direction but a magnitude of 1.
 * This is useful when you want to know the direction of a vector but not its
 * length. It is also very important to keep the calculations anchored to a
 * certain scale. If you don’t normalize your vectors, the resulting rays
 * could be scaled to a very large or small size, which could cause problems
 * while rendering.
 *
 * @param vector the vector to normalize
 * @return t_vector the normalized vector
 */
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
	return (set_vector(x, y, z));
}

/**
 * @brief This function is used to negate a vector. Which means to get his
 * opposite direction.
 *
 * @param vector vector to be negated
 * @return t_vector negated vector
 */
t_vector	negative_vector(t_vector vector)
{
	return (set_vector(-vector.x, -vector.y, -vector.z));
}
