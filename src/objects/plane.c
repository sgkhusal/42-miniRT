/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/17 12:16:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*create_plane(void) // precisa ver se está certo!!
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		minirt_malloc_error("create_plane");
	plane->point = set_point(0, 0, 0);
	plane->orientation = set_vector(0, 1, 0);
	return (plane);
}
