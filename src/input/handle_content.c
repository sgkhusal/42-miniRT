/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/28 22:26:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_qty(int qty, char *element)
{
	if (qty == 0)
		return (print_error_msg2("missing ", element));
	if (qty > 1)
		return (print_error_msg2(element, " declare more than once"));
	return (OK);
}

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
	if (check_qty(ambient, "ambient light") == ERROR
		|| check_qty(camera, "camera") == ERROR
		|| check_qty(light, "light") == ERROR)
		return (ERROR);
	return (OK);
}

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

int	handle_line(char *line, t_rt *rt)
{
	if (ft_strncmp(line, "A ", 2) == 0)
		return (handle_ambient_light(line, &rt->ambient));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (handle_camera(line, &(rt->camera)));
	if (ft_strncmp(line, "L ", 2) == 0)
		return (handle_light(line, &rt->world.light));
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
			status = ERROR;
		}
	}
	if (status == OK)
		set_ambient_light(&rt->world.objects, rt->ambient);
	free_array(lines);
	return (status);
}
