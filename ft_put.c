/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:28:42 by aferryat          #+#    #+#             */
/*   Updated: 2024/11/24 10:45:47 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nb == 0)
		return (write (1, "0", 1));
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	hexa(char *hex, unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += hexa(hex, nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_adress(char *hex, unsigned long nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_adress(hex, nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}
