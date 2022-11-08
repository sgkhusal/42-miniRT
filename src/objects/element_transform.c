/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/08 16:22:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform_sphere(t_sphere *sphere, t_matrix transform)
{
	free_matrix(sphere->transform);
	sphere->transform = transform;
	free_matrix(sphere->inverse);
	sphere->inverse = inverse_matrix(sphere->transform);
	free_matrix(sphere->transpose_inverse);
	sphere->transpose_inverse = transposed_matrix(sphere->inverse);
}

void	set_transform_cylinder(t_cylinder *cylinder, t_matrix transform)
{
	free_matrix(cylinder->transform);
	cylinder->transform = transform;
	free_matrix(cylinder->inverse);
	cylinder->inverse = inverse_matrix(cylinder->transform);
	free_matrix(cylinder->transpose_inverse);
	cylinder->transpose_inverse = transposed_matrix(cylinder->inverse);
}
