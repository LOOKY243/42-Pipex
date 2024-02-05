/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:50:39 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/01 11:21:05 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] - str2[i] != 0)
			return ((int)str1[i] - (int)str2[i]);
		i++;
	}
	return (0);
}
