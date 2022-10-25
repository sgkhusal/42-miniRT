/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:58 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/24 19:24:11 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int validate_sphere_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
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
		status = print_error_msg2("to many or few arguments for sphere: ", line);
	else if (validate_sphere_chars(infos) == ERROR)
		status = ERROR;
	else
	{
		s = create_sphere();
		o = create_object(SPHERE, s);
		o->xyz = transform_coordinates(infos[1], &status);
		// ∗ the sphere diameter: 12.6
		s->radius = transform_double(infos[2], &status) / 2; // vai ter que colocar em outro lugar
		o->color = transform_color(infos[3], &status);
		// criar as matrizes de transformação aqui? ou depois?
		append_object(objs, o);
	}
	free_array(infos);
	return (status);
}

