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

t_material	set_material(void)
{
	t_material	material;

	material.normalized_color = set_vector(1, 1, 1);
	material.ambient = 0.1;
	material.specular = 0.9;
	material.diffuse = 0.9;
	material.shininess = 200;
	return (material);
}
