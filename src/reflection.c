/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/15 10:52:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	reflect(t_vector incident, t_vector normal)
{
	double		scalar;
	t_vector	multiply;
	t_vector	reflected;

	scalar = scalar_product(incident, normal);
	multiply = multiply_vector_by_scalar(normal, 2 * scalar);
	reflected = subtract_vectors(incident, multiply);
	return (reflected);
}
