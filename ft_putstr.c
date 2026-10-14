/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:49:54 by aferryat          #+#    #+#             */
/*   Updated: 2024/11/23 13:56:20 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
		return (ft_putstr ("(null)"));
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
