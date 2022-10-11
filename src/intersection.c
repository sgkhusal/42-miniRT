/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/11 20:17:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*create_intersection(double t, int object)
{
	t_intersection	*intersection;

	intersection = malloc(sizeof(t_intersection));
	if (!intersection)
		minirt_malloc_error("create_intersection");
	intersection->t = t;
	intersection->object = object;
	return (intersection);
}
