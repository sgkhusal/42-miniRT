/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 16:05:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *o, t_matrix transform)
{
	free_matrix(o->transform);
	o->transform = transform;
	free_matrix(o->inverse);
	o->inverse = inverse_matrix(o->transform);
	free_matrix(o->transpose_inverse);
	o->transpose_inverse = transposed_matrix(o->inverse);
}
