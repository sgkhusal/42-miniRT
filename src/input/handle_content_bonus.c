/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 10:59:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Checks the quantity of the mandatory elements in the scene file.
 * There can be only one of each element. It will print an error message if
 * there is more than one of each element or if there is no element. The light
 * is added for bonus as we can have more than one light in the scene in this
 * version.
 *
 * @param qty quantity of each element
 * @param element element name
 * @param light whether there's more than one light in the scene
 * @return int OK if the quantity is valid, otherwise ERROR and the
 * corresponding error message will be printed.
 */
static int	check_qty(int qty, char *element, int light)
{
	if (qty == 0)
		return (print_error_msg2("missing ", element));
	if (qty > 1 && !light)
		return (print_error_msg2(element, " declare more than once"));
	return (OK);
}

/**
 * @brief This function will check if the scene file has all the mandatory
 * elements. If there is no element, or more than one of each element.
 *
 * @param lines array of strings containing the scene file lines
 * @return int OK if the scene file has all the mandatory elements, otherwise
 * ERROR.
 */
static int	check_elements_count(char **lines)
{
	int	i;
	int	camera;
	int	light;
	int	ambient;

	camera = 0;
	light = 0;
	ambient = 0;
	i = -1;
	while (lines[++i])
	{
		if (ft_strncmp(lines[i], "A ", 2) == 0)
			ambient++;
		else if (ft_strncmp(lines[i], "C ", 2) == 0)
			camera++;
		else if (ft_strncmp(lines[i], "L ", 2) == 0)
			light++;
	}
	if (check_qty(ambient, "ambient light", FALSE) == ERROR
		|| check_qty(camera, "camera", FALSE) == ERROR
		|| check_qty(light, "light", TRUE) == ERROR)
		return (ERROR);
	return (OK);
}

/**
 * @brief This function will check that the correct separator is used in the
 * scene file. If the separator is a tab instead of a space, an error message
 * will be printed.
 *
 * @param lines array of strings containing the scene file lines
 * @return int OK if the separator is correct, otherwise ERROR.
 */
static int	check_separator(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_strchr(lines[i], '\t'))
			return (print_error_msg("invalid separator (tab)"));
		i++;
	}
	return (OK);
}

/**
 * @brief This function will go through the scene file lines and check if
 * there is any invalid element. If there is an invalid element, an error
 * message will be printed. It will also check if the the lines don't start
 * with a space. And send each element encountered to the corresponding
 * function to be handled.
 *
 * @param line scene file line
 * @param rt main structure
 */
int	handle_line(char *line, t_rt *rt)
{
	if (ft_strncmp(line, "A ", 2) == 0)
		return (handle_ambient_light(line, &rt->world.ambient));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (handle_camera(line, &(rt->camera)));
	if (ft_strncmp(line, "L ", 2) == 0)
		return (handle_light(line, &(rt->world.lights)));
	if (ft_strncmp(line, "sp ", 3) == 0)
		return (handle_sphere(line, &(rt->world.objects)));
	if (ft_strncmp(line, "pl ", 3) == 0)
		return (handle_plane(line, &(rt->world.objects)));
	if (ft_strncmp(line, "cy ", 3) == 0)
		return (handle_cylinder(line, &(rt->world.objects)));
	if (line[0] == ' ')
		return (print_error_msg("line can't start with space"));
	return (print_error_msg2("invalid element: ", line));
}

/**
 * @brief This function will handle the content of the scene file by sending
 * each check to the corresponding function. It will star by validating the
 * separator, then the quantity of the mandatory elements, and finally the
 * content of the scene file.
 * If there is an error in any of the checks, the function will return ERROR.
 * If everything is OK, it will set the ambient light and free the lines as
 * their content was already handled.
 *
 * @param lines array of strings containing the scene file lines
 * @param rt main structure
 * @return int OK if the scene file is valid, otherwise ERROR.
 */
int	handle_content(char **lines, t_rt *rt)
{
	int		status;
	int		i;

	status = OK;
	if (check_separator(lines) == ERROR)
		status = ERROR;
	else if (check_elements_count(lines) == ERROR)
		status = ERROR;
	i = -1;
	while (lines[++i] && status == OK)
	{
		if (handle_line(lines[i], rt) == ERROR)
		{
			free_objects(&(rt->world.objects));
			free_camera(&rt->camera);
			free_lights(&(rt->world.lights));
			status = ERROR;
		}
	}
	if (status == OK)
		set_ambient_light(&rt->world.objects, rt->world.ambient);
	free_array(lines);
	return (status);
}
