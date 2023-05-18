/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:53:46 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 12:12:27 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Vertex	find_player(char **array, t_Vertex vertex)
{
	vertex.y = 0;
	vertex.x = 0;
	while (array[vertex.y])
	{
		while (array[vertex.y][vertex.x])
		{
			if (array[vertex.y][vertex.x] && array[vertex.y][vertex.x] == 'P')
			{
				return (vertex);
			}
			vertex.x++;
		}
		vertex.x = 0;
		vertex.y++;
	}
	return (vertex);
}

size_t	coll_count(char **array)
{
	size_t	y;
	size_t	x;
	size_t	count;

	y = 0;
	x = 0;
	count = 0;
	while (array[y])
	{
		while (array[y][x])
		{
			if (array[y][x] && array[y][x] == 'C')
				count ++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

t_map	*initialize_map_struct(char **array, t_map *map)
{
	size_t		height;
	t_Vertex	player_pos;

	player_pos = (t_Vertex){0, 0};
	height = 0;
	while (array[height])
		height++;
	map->height = height;
	map->width = ft_strlen(array[0]);
	map->size = map->height * map-> width;
	map->board = array;
	map->coll_total = coll_count(array);
	player_pos = find_player(array, player_pos);
	if (!check_line_lengths(map->board))
		exit_message("Lines are not the same length", map);
	initialize_player(map, player_pos);
	return (map);
}

void	initialize_player(t_map *map, t_Vertex player_pos)
{
	map->player = malloc(sizeof(t_player));
	if (!map->player)
	{
		exit_message("error mallocing player", map);
	}
	map->player->pos = player_pos;
	map->player->moves_taken = 0;
}
