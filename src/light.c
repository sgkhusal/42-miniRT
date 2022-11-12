/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:21:36 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/12 01:19:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	set_point_light(t_point position, t_vector intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}

void	no_light_shading(t_shading *sh)
{
	sh->diffuse = set_vector(0, 0, 0);
	sh->specular = set_vector(0, 0, 0);
}

t_vector	lighting(t_material material, t_light light, t_comp comp)
{
	t_vector	eff_color;
	t_vector	light_vector;
	t_shading	sh;
	t_vector	reflected;
	double		reflected_dot_eye;

	eff_color = multiply_colors(material.normalized_color, light.intensity);
	light_vector = normalize_vector(subtract_points(light.position, comp.point));
	sh.ambient = multiply_vector_by_scalar(eff_color, material.ambient);
	if (scalar_product(light_vector, comp.normalv) < 0)
		no_light_shading(&sh);
	else
	{
		sh.diffuse = multiply_vector_by_scalar(eff_color,
				material.diffuse * scalar_product(light_vector, comp.normalv));
		reflected = reflect(negative_vector(light_vector), comp.normalv);
		reflected_dot_eye = scalar_product(reflected, comp.eyev);
		if (reflected_dot_eye < 0 || check_double_values(reflected_dot_eye, 0))
			sh.specular = set_vector(0, 0, 0);
		else
			sh.specular = multiply_vector_by_scalar(light.intensity,
					pow(reflected_dot_eye, material.shininess) * material.specular);
	}
	//return (add_vectors(sh.ambient, sh.diffuse));
	return (add_vectors(add_vectors(sh.ambient, sh.diffuse), sh.specular));
}
// na scaling, a luz especular não está aparecendo quando aumenta o tamanho do cilindro
// na scaling, a luz especular vai para o infinito quando diminui o tamanho do cilindro

