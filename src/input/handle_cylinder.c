/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/29 16:55:20 by sguilher         ###   ########.fr       */
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

static void	set_cylinder_matrixes(t_object *o, t_point center, double radius,
									t_vector orientation)
{
	t_matrix	translation;
	t_matrix	scaling;
	t_matrix	rotation;
	t_matrix	tmp;

	translation = translation_matrix(center.x, center.y, center.z);
	scaling = scaling_matrix(radius, 1, radius);
	rotation = get_rotation_matrix(orientation);
	tmp = multiply_matrix(translation, rotation);
	set_transform(o, multiply_matrix(tmp, scaling));
	free_matrix(translation);
	free_matrix(scaling);
	free_matrix(rotation);
	free_matrix(tmp);
}

static void	create_and_append_cylinder(t_object **objs, char **infos,
	int *status)
{
	t_object	*cy;
	double		radius;
	double		half_height;
	t_point		center;
	t_vector	orientation;

	cy = create_object(CYLINDER, create_cylinder());
	center = transform_coordinates(infos[1], status);
	orientation = transform_orientation(infos[2], status);
	radius = transform_double(infos[3], status) / 2;
	half_height = transform_double(infos[4], status) / 2;
	cy->shape.cylinder->max = half_height;
	cy->shape.cylinder->min = -half_height;
	cy->material.color = transform_color(infos[5], status);
	set_cylinder_matrixes(cy, center, radius, orientation);
	if (*status == ERROR)
		free_objects(&cy);
	else
		append_object(objs, cy);
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
		status = print_error_msg2("to many or few arguments for cylinder: \
		[center] [height orientation] [diameter] [height] [RGB color]: ", line);
	else if (validate_cylinder_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_cylinder(objs, infos, &status);
	free_array(infos);
	return (status);
}
