/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:24:16 by aferryat          #+#    #+#             */
/*   Updated: 2024/11/24 10:57:40 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	i = 0;
	va_start (list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_checker(format[i], list);
		}
		else if (format[i])
			count += ft_putchar(format[i]);
		i++;
	}
	va_end (list);
	return (count);
}
