/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:55:47 by omathot           #+#    #+#             */
/*   Updated: 2022/12/21 10:59:19 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 1;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && i)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str - '0';
		else
			i = 0;
		str++;
	}
	return (sign * res);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
