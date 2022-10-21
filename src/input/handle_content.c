/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/21 15:46:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_element_valid(char *line)
{
	if (ft_strncmp(line, "A ", 2) == 0)
		return (OK);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (OK);
	if (ft_strncmp(line, "L ", 2) == 0)
		return (OK);
	if (ft_strncmp(line, "sp ", 3) == 0)
		return (OK);
	if (ft_strncmp(line, "pl ", 3) == 0)
		return (OK);
	if (ft_strncmp(line, "cy ", 3) == 0)
		return (OK);
	return (ERROR);
}

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
	if (check_qty(ambient, "ambient light") == ERROR // pode não ter luz ambiente?
		|| check_qty(camera, "camera") == ERROR // pode não ter câmera?
		|| check_qty(light, "light") == ERROR) // acho que pode não ter luz
		return (ERROR);
	return (OK);
}

static int	check_elements(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_element_valid(lines[i]) == ERROR)
		{
			if (lines[i][0] == ' ')
				return (print_error_msg("line can't start with space"));
			return (print_error_msg2("invalid element: ", lines[i]));
		}
		i++;
	}
	return (check_elements_count(lines));
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
	if (check_elements(lines) == ERROR)
		status = ERROR;
	// checks if uses tabs - invalid separator - must use spaces
	i = 0;
	while (lines[i] && status == OK)
	{
		if (handle_line(lines[i], rt) == ERROR)
		{
			// free rt ? - free elements
			status = ERROR;
		}
		i++;
	}
	free_array(lines);
	return (status);
}
