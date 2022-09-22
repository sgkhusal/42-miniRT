/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:53:38 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/01 18:23:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	topositive(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = nb * (-1);
	return (nb);
}

static int	nbsize(int n)
{
	unsigned int	nb;
	int				size;

	size = 0;
	if (n <= 0)
		size++;
	nb = topositive(n);
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*charnb;
	size_t			size;

	nb = topositive(n);
	size = nbsize(n);
	charnb = (char *)malloc((size + 1) * sizeof(char));
	if (!charnb)
		return (NULL);
	charnb[size] = '\0';
	while (size--)
	{
		charnb[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		charnb[0] = '-';
	return (charnb);
}
