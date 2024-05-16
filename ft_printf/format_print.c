/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:47:46 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/07 22:39:00 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_print(char c, va_list args, t_er *checker)
{
	int	s_len;

	s_len = 0;
	if (c == 'd' || c == 'i')
		s_len += ft_modi_putnbr((va_arg(args, int)), checker);
	else if (c == 'u')
		s_len += ft_u_putnbr(va_arg(args, unsigned int), checker);
	else if (c == 's')
		s_len += ft_print_s(va_arg(args, char *), checker);
	else if (c == '%')
		s_len += ft_modi_putchar('%', checker);
	else if (c == 'c')
		s_len += ft_modi_putchar(va_arg(args, int), checker);
	else if (c == 'X')
		s_len += hexa(va_arg(args, unsigned int), 'X', checker);
	else if (c == 'x')
		s_len += hexa(va_arg(args, unsigned int), 'x', checker);
	else if (c == 'p')
	{
		s_len += ft_print_s("0x", checker);
		s_len += hexa(va_arg(args, unsigned long), 'x', checker);
	}
	if (checker->error == 'T')
		return (0);
	return (s_len);
}
