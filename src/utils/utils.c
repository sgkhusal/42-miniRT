/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:09:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 14:23:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is an auxiliary function to compare two different
 * points. It will check each coordinate and return 1 if they are equal, or 0
 * if they are different.
 *
 * @param a point a
 * @param b point b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_equal_points(t_point a, t_point b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
}

/**
 * @brief This is an auxiliary function to check if two double values are
 * equal. It will check if the difference between the two values is less than
 * the epsilon value.
 *
 * @param a double a
 * @param b double b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_double_values(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

/**
 * @brief This function will compare two vectors. It will check each coordinate
 * and return 1 if they are equal, or 0 if they are different.
 *
 * @param a vector a
 * @param b vector b
 * @return t_bool 1 if equal, 0 if different
 */
t_bool	check_equal_vectors(t_vector a, t_vector b)
{
	return (
		check_double_values(a.x, b.x)
		&& check_double_values(a.y, b.y)
		&& check_double_values(a.z, b.z)
		&& check_double_values(a.w, b.w)
	);
}
