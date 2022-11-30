/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/29 16:54:38 by sguilher         ###   ########.fr       */
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

static void	set_plane_matrixes(t_object *o, t_point center,
					t_vector orientation)
{
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	transform;

	translation = translation_matrix(center.x, center.y, center.z);
	rotation = get_rotation_matrix(orientation);
	transform = multiply_matrix(translation, rotation);
	set_transform(o, transform);
	free_matrix(translation);
	free_matrix(rotation);
}

static void	create_and_append_plane(t_object **objs, char **infos, int *status)
{
	t_object	*pl;
	t_point		xyz;
	t_vector	orientation;

	pl = create_object(PLANE, create_plane());
	xyz = transform_coordinates(infos[1], status);
	orientation = transform_orientation(infos[2], status);
	pl->material.color = transform_color(infos[3], status);
	pl->material.specular = 0.2;
	set_plane_matrixes(pl, xyz, orientation);
	if (*status == ERROR)
		free_objects(&pl);
	else
		append_object(objs, pl);
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
		status = print_error_msg2("to many or few arguments for plane: \
		[x,y,z coordinates] [orientation] [RGB color]: ", line);
	else if (validate_plane_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_plane(objs, infos, &status);
	free_array(infos);
	return (status);
}
