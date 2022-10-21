/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:17:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 15:02:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// preencher o elemento e verificar se os valores são válidos
// função de validação para cada tipo de elemento: A, C, L, sp, cy e pl

int	handle_line(char *line, t_rt *rt)
{
	if (line[0] == 'A')
		return (handle_ambient_light(line, rt));
	/* if (line[0] == 'C')
		return (handle_camera(line, rt));
	if (line[0] == 'L')
		return (handle_light(line, rt));
	if (ft_strncmp(line, "sp ", 3 == 0))
		return (handle_sphere(line, rt));
	if (ft_strncmp(line, "pl ", 3 == 0))
		return (handle_plane(line, rt));
	if (ft_strncmp(line, "cy ", 3 == 0))
		return (handle_cylinder(line, rt)); */
	return (OK);
	// função de validação para cada tipo de elemento: A, C, L, sp, cy e pl
}
