/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:51:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/04 15:34:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*add_tuples(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	*sum;
	double	x;
	double	y;
	double	z;
	double	w;

	x = tuple1.x + tuple2.x;
	y = tuple1.y + tuple2.y;
	z = tuple1.z + tuple2.z;
	w = tuple1.w + tuple2.w;
	sum = create_tuple(x, y, z, w);
	return (sum);
}

/* t_tuple	*subtract_tuples(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	*sub;
	double	x;
	double	y;
	double	z;
	double	w;

	x = tuple1.x - tuple2.x;
	y = tuple1.y - tuple2.y;
	z = tuple1.z - tuple2.z;
	w = tuple1.w - tuple2.w;
	sub = create_tuple(x, y, z, w);
	return (sub);
} */

/* t_tuple	*negative_tuple(t_tuple tuple)
{
	t_tuple	*negative;
	double	x;
	double	y;
	double	z;
	double	w;

	x = -tuple.x;
	y = -tuple.y;
	z = -tuple.z;
	w = -tuple.w;
	negative = create_tuple(x, y, z, w);
	return (negative);
} */

t_tuple	*multiply_tuple_by_scalar(t_tuple tuple, double scalar)
{
	t_tuple	*product;
	double	x;
	double	y;
	double	z;
	double	w;

	x = tuple.x * scalar;
	y = tuple.y * scalar;
	z = tuple.z * scalar;
	w = tuple.w * scalar;
	product = create_tuple(x, y, z, w);
	return (product);
}
