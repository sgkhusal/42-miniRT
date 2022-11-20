/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:59:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/20 00:56:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	**create_canvas(void)
{
	t_vector	**canvas;
	int			i;

	canvas = malloc(sizeof(t_vector *) * HEIGHT);
	if (!canvas)
		minirt_malloc_error("create_canvas");
	i = 0;
	while (i < HEIGHT)
	{
		canvas[i] = malloc(sizeof(t_vector) * WIDTH);
		if (!canvas[i])
			minirt_malloc_error("create_canvas");
		i++;
	}
	return (canvas);
}

void	free_canvas(t_vector **canvas)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(canvas[i]);
		i++;
	}
	free(canvas);
}
