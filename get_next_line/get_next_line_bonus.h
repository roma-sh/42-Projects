/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:48:36 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/26 01:03:29 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char					*get_next_line(int fd);
char					*ft_strdup(const char *s);
char					*ft_read(int fd, char *ustals);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strchr(const char *s, int c);
int						ft_strlen(const char *s);

#endif
