/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:54:20 by aferryat          #+#    #+#             */
/*   Updated: 2024/11/24 09:54:27 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_printf(const char *format, ...);
int	ft_checker(char c, va_list list);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	hexa(char *hex, unsigned int nb);
int	ft_adress(char *hex, unsigned long nb);
int	ft_putstr(char *s);

#endif