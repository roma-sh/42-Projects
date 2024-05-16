/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:51:17 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/07 22:36:30 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s, t_er *checker)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += ft_print_s("(null)", checker);
		return (i);
	}
	else
	{
		while (s[i] != '\0')
		{
			if (write(1, &s[i], 1) != 1)
			{
				checker->error = 'T';
				return (0);
			}
			else
				i++;
		}
	}
	return (i);
}

int	ft_modi_putchar(char c, t_er *checker)
{
	if (write(1, &c, 1) != 1)
	{
		checker->error = 'T';
		return (0);
	}
	return (1);
}

int	hexa(unsigned long hex, char c, t_er *checker)
{
	char	*str;
	int		i;

	i = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (hex / 16 > 0)
		i += hexa(hex / 16, c, checker);
	i += ft_modi_putchar(*(str + (hex % 16)), checker);
	return (i);
}
