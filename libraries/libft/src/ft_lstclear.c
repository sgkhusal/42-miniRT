/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:09:19 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/01 18:28:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*tmp;

	if (lst)
	{
		element = *lst;
		while (element->next)
		{
			tmp = element->next;
			ft_lstdelone(element, del);
			element = tmp;
		}
		ft_lstdelone(element, del);
	}
	*lst = NULL;
}
