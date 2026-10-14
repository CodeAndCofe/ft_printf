/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:28:07 by aferryat          #+#    #+#             */
/*   Updated: 2024/11/24 10:54:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else
		count += ft_putnbr_u(va_arg(list, unsigned int));
	return (count);
}

static int	ft_converter(char c, va_list list)
{
	int		count;
	char	*hex;

	count = 0;
	if (c == 'x')
	{
		hex = "0123456789abcdef";
		count += hexa(hex, va_arg(list, unsigned int));
	}
	if (c == 'X')
	{
		hex = "0123456789ABCDEF";
		count += hexa(hex, va_arg(list, unsigned int));
	}
	if (c == 'p')
	{
		hex = "0123456789abcdef";
		count += ft_putstr("0x");
		count += ft_adress(hex, va_arg(list, unsigned long));
	}
	return (count);
}

int	ft_checker(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	if (c == 'i' || c == 'd' || c == 'u')
		count += ft_number (list, c);
	if (c == 'x' || c == 'p' || c == 'X')
		count += ft_converter (c, list);
	if (c == 's')
		count += ft_putstr (va_arg(list, char *));
	return (count);
}
