/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/13 12:28:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_cylinder_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[3]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[4]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[5]) == ERROR)
		return (ERROR);
	return (OK);
}

static void	set_cylinder_matrixes(t_object *o, t_point center, double radius)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (center.x != 0 || center.y != 0 || center.z != 0)
	{
		translation = translation_matrix(center.x, center.y, center.z);
		if (radius != 1)
		{
			scaling = scaling_matrix(radius, 1, radius);
			set_transform(o, multiply_matrix(translation, scaling));
			free_matrix(translation);
			free_matrix(scaling);
		}
		else
			set_transform(o, translation);
	}
	else if (radius != 1)
	{
		scaling = scaling_matrix(radius, 1, radius);
		set_transform(o, scaling);
	}
}

static void	create_and_append_cylinder(t_object **objs, char **infos,
	int *status)
{
	t_object	*c;
	double		radius;
	t_color		color;
	t_point		center;

	c = create_object(CYLINDER, create_cylinder());
	center = transform_coordinates(infos[1], status);
	c->shape.cylinder->orientation = transform_orientation(infos[2], status);//
	radius = transform_double(infos[3], status) / 2;
	c->shape.cylinder->height = transform_double(infos[4], status);//
	color = transform_color(infos[5], status);
	if (*status == ERROR)
	{
		free_objects(&c);
		return ;
	}
	c->material.normalized_color = normalize_color(color);
	set_cylinder_matrixes(c, center, radius); // tem rotação tb
	append_object(objs, c);
}

int	handle_cylinder(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_cylinder"));
	if (total_infos(infos) != 6)
		status = print_error_msg2("to many or few arguments for cylinder: ",
				line);
	else if (validate_cylinder_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_cylinder(objs, infos, &status);
	free_array(infos);
	return (status);
}
