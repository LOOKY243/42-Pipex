/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:00:16 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/08 12:16:53 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				res;
	unsigned char	*str1;
	unsigned char	str2;

	str1 = (unsigned char *)s;
	str2 = (unsigned char)c;
	i = 0;
	res = -1;
	while (str1[i])
	{
		if (str1[i] == str2)
			res = i;
		i++;
	}
	if (str2 == 0)
		res = ft_strlen(s);
	if (res < 0)
		return (NULL);
	return ((char *)&str1[res]);
}
