/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 20:51:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_plane_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_plane(char *line)//, t_object *objs)
{
	char		**infos;
	int			status;
	//t_object	*o;
	//t_plane		*p;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_plane"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for plane: ", line);
	else if (validate_plane_chars(infos) == ERROR)
		status = ERROR;
	/* else
	{
		p = create_plane();
		o = create_object(PLANE, p);
		o->xyz = transform_coordinates(infos[1], &status);
		p->orientation = transform_orientation(infos[2], &status);
		o->color = transform_color(infos[3], &status); // talvez não precise dessa parte
		p->material.normalized_color = normalize_color(o->color);
		// criar as matrizes de transformação aqui? ou depois?
		append_object(objs, o);
	} */
	free_array(infos);
	return (status);
}
