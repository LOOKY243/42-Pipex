/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:15:52 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/08 12:11:36 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str1;
	unsigned char	str2;

	str1 = (unsigned char *)s;
	str2 = (unsigned char)c;
	i = 0;
	while (str1[i])
	{
		if (str1[i] == str2)
			return ((char *)&s[i]);
		i++;
	}
	if (str2 == 0)
		return ((char *)&str1[i]);
	return (NULL);
}
