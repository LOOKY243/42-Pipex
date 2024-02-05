/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:07:30 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/07 19:07:16 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	current = lst;
	if (!lst)
		return (0);
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
