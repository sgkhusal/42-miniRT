/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:27:59 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/13 19:45:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_sphere *sphere, t_matrix transform)
{
	free_matrix(sphere->transform);
	sphere->transform = transform;
}
