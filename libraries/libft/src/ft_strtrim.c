/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:56:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/01 18:25:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	initial_trim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		initial;

	i = 0;
	while (s1[i])
	{
		j = 0;
		initial = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				initial = 0;
			j++;
		}
		if (initial == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int	final_trim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	final;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		final = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				final = 0;
			j++;
		}
		if (final == 1)
			return (i);
		i--;
	}
	return (-2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	i = initial_trim(s1, set);
	end = final_trim(s1, set);
	trim = (char *)malloc((end - i + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	j = 0;
	while (i <= end)
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	if (i == -1)
		trim[0] = '\0';
	trim[j] = '\0';
	return (trim);
}
