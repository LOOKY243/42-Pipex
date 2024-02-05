/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:17:32 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/06 17:29:37 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(int n)
{
	int	power;

	if (n <= 0)
		power = 1;
	else
		power = 0;
	while (n != 0)
	{
		power++;
		n /= 10;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	unsigned int	nb;
	char			*to_char;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	nb = n * sign;
	len = ft_getlen(n);
	to_char = (char *)ft_calloc(len + 1, sizeof(char));
	if (!to_char)
		return (NULL);
	to_char[len--] = '\0';
	while (len >= 0)
	{
		to_char[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign < 0)
		to_char[0] = '-';
	return (to_char);
}
