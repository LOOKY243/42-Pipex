/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:22 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/25 18:12:39 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		str = malloc(sizeof(char) * ft_strlen(s2) + 2);
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}
