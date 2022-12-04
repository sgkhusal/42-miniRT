/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 09:21:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will validate the information of the light. The first
 * info is the position of the light, which must be a valid vector. The second
 * info is the brightness of the light, which must be a double between 0 and 1.
 * The third info is the color of the light, which must be a valid RGB color
 * (not mandatory).
 *
 * @param infos the information of the light, which is a string
 * @return int 0 if the information is valid, 1 otherwise
 */
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

/**
 * @brief This function will handle the light information. It will split the
 * information in the string by the separator ' ', validate the information,
 * transform the information in the correct type and store it in t_light struct
 * variables. Then, it will free the information that was already parsed.
 *
 * @param line the information of the light
 * @param light the t_light struct
 * @return int ERROR if any information is invalid or error occurs, OK otherwise
 */
int	handle_light(char *line, t_light *light)
{
	char		**infos;
	int			status;
	double		brightness;
	t_vector	color;

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
	{
		light->position = transform_coordinates(infos[1], &status);
		if (check_equal_points(light->position, set_point(0, 0, 0)))
			light->position = set_point(0, 0, 0.0001);
		brightness = transform_ratio(infos[2], &status);
		color = transform_color(infos[3], &status);
		light->intensity = multiply_vector_by_scalar(color, brightness);
	}
	free_array(infos);
	return (status);
}
