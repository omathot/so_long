/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:33:38 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 12:39:59 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	if (map->board)
	{
		while (i < map->height)
		{
			free(map->board[i]);
			i++;
		}
		free(map->board);
	}
	if (map->sprites)
		free(map->sprites);
	free(map->collectible);
	free(map->player);
	free(map);
}

void	exit_message(char *msg, t_map *map)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	exit_error(char *msg, char *to_free)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free(to_free);
	exit(EXIT_FAILURE);
}
