/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 113:573:59 by elraira-         ###   ########.fr       */
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

t_matrix	cylinder_rotation_matrix(t_vector orientation)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	rotation;

	if (check_equal_vectors(set_vector(0, 1, 0), orientation))
		return (identity_matrix(4));
	else if (check_equal_vectors(set_vector(0, -1, 0), orientation))
		return (rotation_x_matrix(M_PI));
	else if (check_equal_vectors(set_vector(1, 0, 0), orientation))
		return (rotation_z_matrix(-M_PI / 2));
	else if (check_equal_vectors(set_vector(-1, 0, 0), orientation))
		return (rotation_z_matrix(M_PI / 2));
	else if (check_equal_vectors(set_vector(0, 0, 1), orientation))
		return (rotation_x_matrix(M_PI / 2));
	else if (check_equal_vectors(set_vector(0, 0, -1), orientation))
		return (rotation_x_matrix(-M_PI / 2));
	if (check_double_values(orientation.y, 0))
	{
		rotation_x = rotation_x_matrix(M_PI / 2);
		rotation_y = rotation_y_matrix(atan(orientation.x / orientation.z));
		rotation = multiply_matrix(rotation_y, rotation_x);
		free_matrix(rotation_y);
	}
	else
	{
		rotation_x = rotation_x_matrix(atan(orientation.z / orientation.y));
		rotation_z = rotation_z_matrix(atan(-orientation.x / orientation.y));
		rotation = multiply_matrix(rotation_z, rotation_x);
		free_matrix(rotation_z);
	}
	free_matrix(rotation_x);
	return (rotation);
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
	rotation = cylinder_rotation_matrix(orientation);
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
	t_object	*c;
	double		radius;
	double		half_height;
	t_point		center;
	t_vector	orientation;

	c = create_object(CYLINDER, create_cylinder());
	center = transform_coordinates(infos[1], status);
	orientation = transform_orientation(infos[2], status);
	radius = transform_double(infos[3], status) / 2;
	half_height = transform_double(infos[4], status) / 2;
	c->shape.cylinder->max = half_height;
	c->shape.cylinder->min = -half_height;
	c->material.color = transform_color(infos[5], status);
	set_cylinder_matrixes(c, center, radius, orientation);
	append_object(objs, c);
	if (*status == ERROR)
		free_objects(&c);
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
