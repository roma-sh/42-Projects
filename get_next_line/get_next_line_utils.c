/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:34:18 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/26 00:12:41 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*cop;
	size_t	size;
	size_t	i;

	cop = (char *)s;
	size = ft_strlen(s);
	cop = (char *)malloc(size + 1);
	if (!cop)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cop[i] = s[i];
		i++;
	}
	cop[i] = '\0';
	return (cop);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*s;

	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *)malloc(i + j + 1);
	if (!s)
		return (NULL);
	while (i-- && s1[k] != '\0')
	{
		s[k] = s1[k];
		k++;
	}
	i = 0;
	while (i < j && s2[i] != '\0')
	{
		s[k] = s2[i];
		k++;
		i++;
	}
	s[k] = 0;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
