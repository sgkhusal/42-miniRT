/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:59:31 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/30 14:05:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to create a canvas, which is a 2D array of
 * pixels.  * The canvas is used to store the colors of the pixels that will be
 * rendered.
 *
 * @param width width of the canvas
 * @param height height of the canvas
 * @return t_canvas canvas
 */
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

/**
 * @brief This function is used to free the canvas.
 *
 * @param canvas canvas to be freed
 */
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
