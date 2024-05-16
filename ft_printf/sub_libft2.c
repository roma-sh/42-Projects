/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_libft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:57:46 by rshatra           #+#    #+#             */
/*   Updated: 2024/04/07 22:38:07 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_submodi_putnbr(int n, t_er *checker)
{
	int	i;
	int	c;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) != 1)
		{
			checker->error = 'T';
			return (0);
		}
		else
			i++;
	}
	if (n / 10 != 0)
		i += ft_submodi_putnbr(n / 10, checker);
	c = ((n % 10) + '0');
	if (write(1, &c, 1) != 1)
	{
		checker->error = 'T';
		return (0);
	}
	return (++i);
}

int	ft_modi_putnbr(long long n, t_er *checker)
{
	int		i;

	i = 0;
	if (n < -2147483648 || n > 2147483647)
	{
		checker->error = 'T';
		return (0);
	}
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
		{
			checker->error = 'T';
			return (0);
		}
		else
			return (11);
	}
	i += ft_submodi_putnbr(n, checker);
	return (i);
}

int	ft_u_putnbr(unsigned long n, t_er *checker)
{
	char	c;
	int		i;

	i = 0;
	if (n < 0 || n > 4294967295)
	{
		checker->error = 'T';
		return (0);
	}
	if (n / 10 != 0)
		i += ft_modi_putnbr(n / 10, checker);
	c = ((n % 10) + '0');
	if (write(1, &c, 1) != 1)
	{
		checker->error = 'T';
		return (0);
	}
	else
		i++;
	return (i);
}
