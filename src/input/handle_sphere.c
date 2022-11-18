/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:58 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/18 19:53:29 by sguilher         ###   ########.fr       */
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

static void	create_and_append_sphere(t_object **objs, char **infos, int *status)
{
	t_object	*s;
	double		radius;
	t_point		center;

	s = create_object(SPHERE, create_sphere());
	center = transform_coordinates(infos[1], status);
	radius = transform_double(infos[2], status) / 2;
	s->material.color = transform_color(infos[3], status);
	set_sphere_matrixes(s, center, radius);
	append_object(objs, s);
	if (*status == ERROR)
		free_objects(&s);
}

int	handle_sphere(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_sphere"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments in sphere: ", line);
	else if (validate_sphere_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_sphere(objs, infos, &status);
	free_array(infos);
	return (status);
}
