/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:39:20 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/07 22:48:59 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int			s_len;
	int			i;
	va_list		args;
	t_er		checker;

	i = -1;
	s_len = 0;
	va_start(args, s);
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			s_len += ft_modi_putchar(s[i], &checker);
		else
		{
			if (ft_strchr("cspdiuxX%", s[i + 1]))
			{
				s_len += format_print(s[i++ + 1], args, &checker);
			}
			else
				return (-1);
		}
	}
	if (checker.error == 'T')
		return (va_end(args), -1);
	return (s_len);
}

/* int	main(void)
{
	int	a = 99;
	int	b = 22;
	char *c = "Hell";
	char d = 'Q';
	int	e = -1;
	int	f = 0XF7A4;
	int	*g = &a;
	int	x = ft_printf("%% a=%u, b=%d, c=%s, d=%c, e=%x,
	f=%X, g=%p\n",a,b,c,d,e,f,(void *)-55);
	int	y = printf("%% a=%u, b=%d, c=%s, d=%c, e=%x,
	f=%X, g=%p\n",a,b,c,d,e,f,(void *)-55);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return (0);
}
 */
