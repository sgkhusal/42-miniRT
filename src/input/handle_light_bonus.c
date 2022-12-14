/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 11:21:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will validate the information of the light. The first
 * info is the position of the light, which must be a valid vector. The second
 * info is the brightness of the light, which must be a double between 0 and 1.
 * The third info is the color of the light, which must be a valid RGB color
 * (for the bonus part).
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
 * @brief This function will create the light element. It will allocate memory
 * for the light element and transform the information of the light from the
 * scene file into the light properties. If no error occurs, the function will
 * append the light element to the list of lights. If an error occurs, the
 * function will free the memory allocated for the light element.
 *
 * @param head the head of the list of lights
 * @param infos the information of the light, which is a string
 * @param status the status of the scene file
 */
static void	create_and_append_light(t_light **head, char **infos, int *status)
{
	double		brightness;
	t_vector	color;
	t_light		*light;
	t_point		position;

	position = transform_coordinates(infos[1], status);
	if (check_equal_points(position, set_point(0, 0, 0)))
		position = set_point(0, 0, 0.0001);
	brightness = transform_ratio(infos[2], status);
	color = transform_color(infos[3], status);
	if (*status == ERROR)
		return ;
	light = create_point_light(position,
			multiply_vector_by_scalar(color, brightness));
	append_light(head, light);
}

/**
  * @brief This function will handle the light information. It will split the
  * information in the string by the separator ' ' and validate the information.
  * If the information is valid, it will create a light and append it to the
  * list of lights.
  *
  * @param line the information of the light
  * @param light the t_light struct
  * @return int ERROR if any information is invalid or error occurs,
  * OK otherwise.
  */
int	handle_light(char *line, t_light **head)
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
		create_and_append_light(head, infos, &status);
	free_array(infos);
	return (status);
}
