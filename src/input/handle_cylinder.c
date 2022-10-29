/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:54:02 by sguilher         ###   ########.fr       */
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

int	handle_cylinder(char *line)//, t_object *objs)
{
	char		**infos;
	int			status;
	//t_object	*o;
	//t_cylinder	*c;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_cylinder"));
	if (total_infos(infos) != 6)
		status = print_error_msg2("to many or few arguments for cylinder: ",
				line);
	else if (validate_cylinder_chars(infos) == ERROR)
		status = ERROR;
	/* else
	{
		c = create_cylinder();
		o = create_object(CYLINDER, c);
		o->xyz = transform_coordinates(infos[1], &status);
		c->orientation = transform_orientation(infos[2], &status);
		// the cylinder diameter: 14.2
		c->radius = transform_double(infos[3], &status) / 2;
		// the cylinder height: 21.42
		c->height = transform_double(infos[4], &status);
		o->color = transform_color(infos[5], &status); // talvez não precise dessa parte
		c->material.normalized_color = normalize_color(o->color);
		// criar as matrizes de transformação aqui? ou depois?
		append_object(objs, o);
	} */
	free_array(infos);
	return (status);
}
