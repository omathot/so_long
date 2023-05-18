/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:03:39 by oscarmathot       #+#    #+#             */
/*   Updated: 2022/12/22 10:34:38 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printchar(int c)
{	
	write(1, &c, 1);
	return (1);
}

int	eval_format(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putdigit(va_arg(args, int)));
	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long int)));
	if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), format));
	if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	alloc_check(const char *format)
{
	if (!format)
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		wrt;
	va_list	args;

	i = 0;
	wrt = 0;
	va_start(args, format);
	alloc_check(format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			i -= 1;
			break ;
		}
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[++i]))
		{
			wrt += eval_format(args, format[i]);
		}
		else
			wrt += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (wrt);
}
