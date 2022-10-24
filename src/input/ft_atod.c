/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:10:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/24 19:16:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_atod(char *nb)
{
	double	n;
	int		point;
	int		size;

	size = ft_strlen(nb);
	point = 0;
	while (nb[point] != '.' && point < size)
		point++;
	if (point == size)
		return (ft_atoi(nb));
	ft_memmove(nb + point, nb + point + 1, size - point);
	n = ft_atoi(nb);
	n /= pow(10, size - point - 1);
	return (n);
}
