/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:28 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/07 19:02:30 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (!lst || !f)
		return ;
	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
