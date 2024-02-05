/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:12:11 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/25 18:12:14 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countsplit(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			if (s[i] == '\'' || s[i] == '\"')
			{
				i++;
				while (s[i] && s[i] != '\'' && s[i] != '\"')
					i++;
				i++;
			}
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	*ft_prealloc(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			i++;
			while (s[i] && s[i] != '\'' && s[i] != '\"')
			{
				count++;
				i++;
			}
			i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (ft_calloc((count + 1), sizeof(char)));
}

void	ft_split2(const char *s, char **strs, size_t i[3])
{
	if (s[i[0]] == '\'' || s[i[0]] == '\"')
	{
		i[0]++;
		while (s[i[0]] && s[i[0]] != '\'' && s[i[0]] != '\"')
			strs[i[2]][i[1]++] = s[i[0]++];
		i[0]++;
	}
	else
		strs[i[2]][i[1]++] = s[i[0]++];
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i[3];

	if (!s)
		return (NULL);
	strs = ft_calloc(ft_countsplit(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i[2] = 0;
	i[0] = 0;
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		i[1] = 0;
		strs[i[2]] = ft_prealloc(s, c, i[0]);
		while (s[i[0]] != c && s[i[0]])
			ft_split2(s, strs, i);
		i[2]++;
	}
	return (strs);
}
