/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:48:49 by gmarre            #+#    #+#             */
/*   Updated: 2023/10/31 17:26:37 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	ptr = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == cc)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
