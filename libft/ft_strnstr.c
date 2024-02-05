/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:27:05 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/08 11:54:49 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i + j < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] == big[i + j] && big[i + j] && i + j < len)
				j++;
			if ((j == len || j == ft_strlen(little))
				&& ft_strlen(little) <= len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
