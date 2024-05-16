/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:48:07 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/26 01:09:26 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*isolate_line(char *current_read)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (current_read[i] != '\0' && current_read[i] != '\n')
		i++;
	if (current_read[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	while (current_read[j] && i > 0)
	{
		temp[j] = current_read[j];
		j++;
		i--;
	}
	temp[j] = '\0';
	return (temp);
}

char	*remain(char *current_read)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	j = ft_strlen(current_read);
	while (current_read[i] != '\0' && current_read[i] != '\n')
		i++;
	if (current_read[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (j - i + 1));
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	while (current_read[i] != '\0' && i < j)
	{
		temp[k++] = current_read[i++];
	}
	temp[k] = '\0';
	free (current_read);
	return (temp);
}

char	*ft_read(int fd, char *ustals)
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*temp;

	if (read(fd, NULL, 0) < 0)
	{
		free (ustals);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		temp = ustals;
		ustals = ft_strjoin(ustals, buffer);
		free (temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read == 0 && ustals[0] == 0)
		return (free (ustals), NULL);
	return (ustals);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ustals[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ustals[fd])
		ustals[fd] = ft_strdup("");
	ustals[fd] = ft_read(fd, ustals[fd]);
	if (!ustals[fd])
	{
		free (ustals[fd]);
		return (NULL);
	}
	line = isolate_line(ustals[fd]);
	ustals[fd] = remain(ustals[fd]);
	return (line);
}
