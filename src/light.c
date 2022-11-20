/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:21:36 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/20 10:37:07 by sguilher         ###   ########.fr       */
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

/*
reflect_dot_eye: the cosine of the angle between the reflection vector and the
eye vector. A negative number means the light reflects away from the eye.
*/
t_vector	get_specular(t_material m, t_light light, t_comp comp,
							t_vector light_vect)
{
	t_vector	specular;
	t_vector	reflected;
	double		reflected_dot_eye;

	reflected = reflect(negative_vector(light_vect), comp.normalv);
	reflected_dot_eye = scalar_product(reflected, comp.eyev);
	if (reflected_dot_eye < 0 || check_double_values(reflected_dot_eye, 0))
		specular = set_vector(0, 0, 0);
	else
		specular = multiply_vector_by_scalar(light.intensity,
			pow(reflected_dot_eye, m.shininess) * m.specular);
	return (specular);
}

/*
light_vect: the direction from the point to the light source
light_dot_normal: the cosine of the angle between the light vector and the
normal vector. A negative number means the light is on the other side of the
surface.
*/
t_vector	lighting(t_material m, t_light light, t_comp comp, t_bool shadow)
{
	t_vector	eff_color;
	t_vector	light_vect;
	t_shading	sh;
	double		light_dot_normal;

	//printf("light bright: %f %f %f\n", light.intensity.x, light.intensity.y, light.intensity.z);
	//printf("material color: %f %f %f\n", material.color.x, material.color.y, material.color.z);
	eff_color = multiply_colors(m.color, light.intensity);
	light_vect = normalize_vector(subtract_points(light.position, comp.point));
	sh.ambient = multiply_colors(eff_color, m.ambient); // tenho a impressão que a ambient não teria que multiplicar pela intensity antes... - light 0,0,0
	light_dot_normal = scalar_product(light_vect, comp.normalv);
	if (light_dot_normal < 0 || shadow == TRUE)
		return (sh.ambient);
	sh.diffuse = multiply_vector_by_scalar(eff_color,
		m.diffuse * light_dot_normal);
	sh.specular = get_specular(m, light, comp, light_vect);
	//return (add_vectors(sh.ambient, sh.diffuse));
	return (add_vectors(add_vectors(sh.ambient, sh.diffuse), sh.specular));
}

t_bool	is_shadowed(t_world w, t_point point)
{
	t_vector	v;
	double		distance;
	t_ray		r;
	t_intersection_list	list;
	t_intersection	*hit;

	v = subtract_points(w.light.position, point);
	distance = vector_length(v);
	r = set_ray(point, normalize_vector(v));
	list = intersect_world(w, r);
	if (list.total == 0)
		return (FALSE);
	hit = get_hit_intersection(list);
	if (hit && hit->t < distance)
	{
		free_intersection_list(&list);
		return (TRUE);
	}
	free_intersection_list(&list);
	return (FALSE);
}

t_vector	shade_hit(t_world world, t_comp comps)
{
	t_bool	shadow;

	shadow = is_shadowed(world, comps.over_point);
	return (lighting(comps.xs->object->material, world.light, comps, shadow));
}
