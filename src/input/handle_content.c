/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/20 23:34:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_element_valid(char *line)
{
	// considera inválido se o início tiver espaço??
	if (line[0] == 'A' && line[1] == ' ')
		return (OK);
	if (line[0] == 'C' && line[1] == ' ')
		return (OK);
	if (line[0] == 'L' && line[1] == ' ')
		return (OK);
	if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (OK);
	if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (OK);
	if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
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

int	check_elements_qty(char **lines)
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
		if (lines[i][0] == 'A' && lines[i][1] == ' ')
			ambient++;
		else if (lines[i][0] == 'C' && lines[i][1] == ' ')
			camera++;
		else if (lines[i][0] == 'L' && lines[i][1] == ' ')
			light++;
	}
	if (check_qty(ambient, "ambient light") == ERROR // pode não ter luz ambiente?
		|| check_qty(camera, "camera") == ERROR // pode não ter câmera?
		|| check_qty(light, "light") == ERROR) // acho que pode não ter luz
		return (ERROR); // free lines
	return (OK);
}

int	check_elements(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_element_valid(lines[i]) == ERROR)
		{
			// free lines
			return (print_error_msg2("invalid element: ", lines[i]));
		}
		i++;
	}
	return (check_elements_qty(lines));
}

// preencher o elemento e verificar se os valores são válidos
// função de validação para cada tipo de elemento: A, C, L, sp, cy e pl

t_rt	transform_input(char **lines)
{
	t_rt	rt;
	int		i;
	char	**infos;

	//rt = init_rt();
	i = 0;
	while (lines[i])
	{
		infos = ft_split(lines[i], ' ');
		if (infos[0][0] == 'A')
			fill_ambient_light(&rt, infos); // se dar pau te, que dar free na lines
		else if (infos[0][0] == 'C')
			fill_camera(&rt, infos);
		else if (infos[0][0] == 'L')
			fill_light(&rt, infos);
		else if (infos[0][0] == 's' && infos[0][1] == 'p')
			fill_sphere(&rt, infos);
		else if (infos[0][0] == 'p' && infos[0][1] == 'l')
			fill_plane(&rt, infos);
		else if (infos[0][0] == 'c' && infos[0][1] == 'y')
			fill_cylinder(&rt, infos);
		// função de validação para cada tipo de elemento: A, C, L, sp, cy e pl
	}
	return (rt);
}

t_rt	handle_content(char *content)
{
	char	**lines;
	t_rt	rt;

	lines = ft_split(content, '\n');
	free(content);
	if (!lines || !*lines)
		exit (print_error_msg("empty file"));
	if (check_elements(lines) == ERROR)
		exit (EXIT_FAILURE);
	rt = transform_input(lines);
	return (rt);
}

