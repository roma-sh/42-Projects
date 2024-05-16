/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:06:18 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/07 22:35:08 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>

# include "./libft/libft.h"

typedef struct error_check
{
	char				error;
}					t_er;

int					ft_printf(const char *s, ...);
int					ft_modi_putnbr(long long n, t_er *checker);
int					ft_u_putnbr(unsigned long n, t_er *checker);
int					ft_print_s(char *s, t_er *checker);
int					ft_modi_putchar(char c, t_er *checker);
int					format_print(char c, va_list args, t_er *checker);
int					hexa(unsigned long hex, char c, t_er *checker);

#endif
