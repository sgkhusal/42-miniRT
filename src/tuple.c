/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:08:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/04 15:26:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*create_tuple(double x, double y, double z, double w)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		minirt_malloc_error("create_tuple");
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}

t_tuple	*create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, 1.0));
}

t_tuple	*create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, 0.0));
}
