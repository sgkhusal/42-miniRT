/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:21:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/15 11:3500 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Set the default material properties to be used in most scenarios.
 *
 * @return t_material t_material struct containing the default material
 * properties.
 */
t_material	set_material(void)
{
	t_material	material;

	material.color = set_vector(1, 1, 1);
	material.ambient = set_vector(0.1, 0.1, 0.1);
	material.specular = 0.9;
	material.diffuse = 0.9;
	material.shininess = 200;
	return (material);
}
