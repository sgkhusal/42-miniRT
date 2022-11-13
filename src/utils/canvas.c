/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:59:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/28 22:35:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	**create_canvas(void)
{
	t_vector	**canvas;
	int			i;
	int			j;

	canvas = malloc(sizeof(t_vector *) * HEIGHT);
	if (!canvas)
		minirt_malloc_error("create_canvas");
	i = 0;
	while (i < HEIGHT)
	{
		canvas[i] = malloc(sizeof(t_vector) * WIDTH);
		if (!canvas[i])
			minirt_malloc_error("create_canvas");
		j = 0;
		while (j < WIDTH)
		{
			canvas[i][j] = set_vector(0, 0, 0);
			j++;
		}
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
