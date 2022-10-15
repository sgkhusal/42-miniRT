/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/14 20:33:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_sphere *sphere, t_matrix transform)
{
	free_matrix(sphere->transform);
	sphere->transform = transform;
	free_matrix(sphere->inverse);
	sphere->inverse = inverse_matrix(sphere->transform);
	free_matrix(sphere->transpose_inverse);
	sphere->transpose_inverse = transposed_matrix(sphere->inverse);
}
