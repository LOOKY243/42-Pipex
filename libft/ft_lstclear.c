/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:26:24 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/07 14:45:44 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del || !lst || !*lst)
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
