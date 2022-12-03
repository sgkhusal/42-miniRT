/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 14:16:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_light_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_double_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

static void	create_and_append_light(t_light *light, char **infos, int *status)
{
	double		brightness;
	t_vector	color;

	light->position = transform_coordinates(infos[1], status);
	if (check_equal_points(light->position, set_point(0, 0, 0)))
		light->position = set_point(0, 0, 0.0001);
	brightness = transform_ratio(infos[2], status);
	color = transform_color(infos[3], status);
	color = set_vector(1, 1, 1);
	light->intensity = multiply_vector_by_scalar(color, brightness);
}

int	handle_light(char *line, t_light *light)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_light"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for light: ",
				"[light point] [light brightness ratio] [RGB color]");
	else if (validate_light_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_light(light, infos, &status);
	free_array(infos);
	return (status);
}
