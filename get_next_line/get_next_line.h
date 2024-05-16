/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:34:33 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/25 21:48:47 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char					*get_next_line(int fd);
char					*ft_strdup(const char *s);
char					*ft_read(int fd, char *ustals);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strchr(const char *s, int c);
int						ft_strlen(const char *s);

#endif
