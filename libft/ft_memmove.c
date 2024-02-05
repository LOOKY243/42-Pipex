/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:30 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/08 11:31:19 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	unsigned const char	*char_src;

	if (!src && !dest)
		return (NULL);
	char_dest = (unsigned char *) dest;
	char_src = (const unsigned char *) src;
	if (src >= dest)
	{
		while (n--)
			*char_dest++ = *char_src++;
		return (dest);
	}
	else
	{
		char_dest = char_dest + n - 1;
		char_src = char_src + n - 1;
		while (n--)
			*char_dest-- = *char_src--;
		return (dest);
	}
	return (dest);
}
