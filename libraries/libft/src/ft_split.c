/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:55:08 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/01 18:25:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wcount(char const *s, char c)
{
	int		i;
	size_t	count;

	if (!s || !s[0])
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c && s[0])
		count = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	lcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

static void	free_pointer(char **p, int i)
{
	while (i <= 0)
	{
		free(p[i]);
		p[i] = NULL;
		i--;
	}
	free(p);
	p = NULL;
}

static void	ft_split_split(char const *s, char **words, char c, size_t wc)
{
	size_t	i;
	int		k;
	size_t	lc;

	i = 0;
	k = 0;
	while (i < wc)
	{
		while (s[k] == c && s[k])
			k++;
		lc = lcount(&s[k], c);
		words[i] = ft_substr(&s[k], 0, lc);
		if (!words[i])
		{
			free_pointer(words, i);
			return ;
		}
		k = k + lc;
		i++;
	}
	words[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**words;

	if (!s)
		return (NULL);
	wc = wcount(s, c);
	words = (char **)malloc((wc + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	ft_split_split(s, words, c, wc);
	return (words);
}
