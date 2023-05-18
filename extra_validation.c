/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:53:48 by omathot           #+#    #+#             */
/*   Updated: 2023/04/18 16:36:50 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_filename(const char *filename, const char *ext)
{
	size_t	len_filename;
	size_t	len_ext;
	size_t	i;

	i = 0;
	len_filename = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_filename < len_ext)
		return (false);
	while (i < len_ext)
	{
		if (filename[len_filename - len_ext + i] != ext[i])
			return (false);
		i++;
	}
	return (true);
}

bool	check_line_lengths(char **board)
{
	size_t	y;
	size_t	length;

	y = 0;
	length = ft_strlen(board[y]);
	while (board[y])
	{
		if (ft_strlen(board[y]) != length)
			return (false);
		y++;
	}
	return (true);
}
