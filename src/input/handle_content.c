/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 23:43:41 by sguilher         ###   ########.fr       */
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
		if (lines[i][0] == 'A')
			ambient++;
		else if (lines[i][0] == 'C')
			camera++;
		else if (lines[i][0] == 'L')
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
	if (line[0] == 'A')
		return (handle_ambient_light(line, &rt->ambient));
	if (line[0] == 'C')
		return (handle_camera(line, &rt->camera));
	if (line[0] == 'L')
		return (handle_light(line, &rt->light));
	if (ft_strncmp(line, "sp ", 3) == 0)
		return (handle_sphere(line, &(rt->objects)));
	if (ft_strncmp(line, "pl ", 3) == 0)
		return (handle_plane(line));//, rt->objects));
	if (ft_strncmp(line, "cy ", 3) == 0)
		return (handle_cylinder(line));//, rt->objects));
	if (line[0] == ' ')
		return (print_error_msg("line can't start with space"));
	return (print_error_msg2("invalid element: ", line));
}

int	handle_content(char *content, t_rt	*rt)
{
	char	**lines;
	int		status;
	int		i;

	status = OK;
	lines = ft_split(content, '\n');
	free(content);
	if (!lines || !*lines)
		return (print_error_msg("empty file"));
	if (check_elements_count(lines) == ERROR)
		status = ERROR;
	if (check_separator(lines) == ERROR)
		status = ERROR;
	i = -1;
	rt->objects = NULL;
	while (lines[++i] && status == OK)
	{
		printf("linha = %s\n", lines[i]);
		if (handle_line(lines[i], rt) == ERROR)
		{
			free_objects(&(rt->objects));
			status = ERROR;
		}
	}
	free_array(lines);
	return (status);
}
