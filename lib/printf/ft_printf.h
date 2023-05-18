/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:40:22 by omathot           #+#    #+#             */
/*   Updated: 2023/04/18 18:14:25 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printchar(int c);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);
int		eval_format(va_list args, const char format);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_putdigit(int n);
int		ft_hexa_len(unsigned int n);
void	ft_put_hexa(unsigned int n, const char format);
int		ft_print_hexa(unsigned int n, const char format);
int		ft_num_len(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_ptr_len(uintptr_t n);
void	ft_put_ptr(uintptr_t n);
int		ft_print_ptr(unsigned long int ptr);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*make_zero(char *str);
int		ft_count(long n);

#endif
