/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 12:13:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_plane_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

static void	set_plane_matrixes(t_object *o, t_point center)
{
	t_matrix	translation;

	if (center.x != 0 || center.y != 0 || center.z != 0)
	{
		translation = translation_matrix(center.x, center.y, center.z);
		set_transform(o, translation);
	}
}

static void	create_and_append_plane(t_object **objs, char **infos, int *status)
{
	t_object	*p;
	//t_color		color;
	t_point		xyz;

	p = create_object(PLANE, create_plane());
	xyz = transform_coordinates(infos[1], status);
	p->shape.plane->orientation = transform_orientation(infos[2], status);
	//color = transform_color(infos[3], status);
	if (*status == ERROR)
	{
		free_objects(&p);
		return ;
	}
	//p->material.normalized_color = normalize_color(color);
	set_plane_matrixes(p, xyz); // falta rotação
	append_object(objs, p);
}

int	handle_plane(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_plane"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for plane: ", line);
	else if (validate_plane_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_plane(objs, infos, &status);
	free_array(infos);
	return (status);
}
