/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:21:46 by omathot           #+#    #+#             */
/*   Updated: 2022/12/19 10:37:23 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*number;
	int		len;

	len = ft_num_len(n);
	number = (char *) malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len] = '\0';
	while (n != 0)
	{
		number[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (number);
}

int	ft_print_unsigned(unsigned int n)
{
	int		wrt;
	char	*number;

	wrt = 0;
	if (n == 0)
		wrt += write(1, "0", 1);
	else
	{
		number = ft_utoa(n);
		wrt += ft_printstr(number);
		free(number);
	}
	return (wrt);
}
