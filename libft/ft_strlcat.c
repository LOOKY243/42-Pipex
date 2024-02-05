/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:59:58 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/03 13:19:24 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (dest_len + i < size - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (src_len + dest_len);
}
