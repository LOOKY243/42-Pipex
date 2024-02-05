/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:12:20 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/08 11:31:06 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	unsigned const char	*char_src;
	unsigned int		i;

	if (!src && !dest)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
