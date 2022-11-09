/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:58 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 17:13:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_sphere_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

static void	set_sphere_matrixes(t_object *o, t_point center, double radius)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (center.x != 0 || center.y != 0 || center.z != 0)
	{
		translation = translation_matrix(center.x, center.y, center.z);
		if (radius != 1)
		{
			scaling = scaling_matrix(radius, radius, radius);
			set_transform(o, multiply_matrix(translation, scaling));
			free_matrix(translation);
			free_matrix(scaling);
		}
		else
			set_transform(o, translation);
	}
	else if (radius != 1)
	{
		scaling = scaling_matrix(radius, radius, radius);
		set_transform(o, scaling);
	}
}

int	handle_sphere(char *line, t_object **objs)
{
	char		**infos;
	int			status;
	t_object	*o;
	t_sphere	*s;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_sphere"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments in sphere: ", line);
	else if (validate_sphere_chars(infos) == ERROR)
		status = ERROR;
	else
	{
		s = create_sphere();
		o = create_object(SPHERE, s);
		o->xyz = transform_coordinates(infos[1], &status); // talvez possa tirar
		o->color = transform_color(infos[3], &status); // talvez possa tirar
		o->material.normalized_color = normalize_color(o->color);
		set_sphere_matrixes(o, o->xyz, transform_double(infos[2], &status) / 2);
		append_object(objs, o);
	}
	free_array(infos);
	return (status);
}
