/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:28:04 by omathot           #+#    #+#             */
/*   Updated: 2022/12/21 14:15:47 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

/*

char *base = "0123456789ABCDEF"
ft_putchar_fd(base[n])

*/

void	ft_put_hexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hexa(n / 16, format);
		ft_put_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd((n + '0'), 1);
		}
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hexa(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexa(n, format);
	return (ft_hexa_len(n));
}
