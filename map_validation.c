/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:50:22 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 10:38:51 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	check_whitespace(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{	
		if (content[i] == '\n' && content[i + 1] == '\n')
		{
			free(content);
			exit_message("Map has empty lines", NULL);
		}
		i++;
	}
}

void	validate_map(char *content)
{
	size_t	collectibles;
	size_t	player;
	size_t	exit;
	size_t	i;

	collectibles = 0;
	player = 0;
	exit = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == 'C')
			collectibles++;
		else if (content[i] == 'P')
			player++;
		else if (content[i] == 'E')
			exit++;
		else
			check_chars(content[i]);
		i++;
	}
	if (collectibles < 1 || player != 1 || exit != 1)
		exit_error("This map is invalid", NULL);
}

void	check_chars(char content)
{
	if (content != '1' && content != '0' && content != '\n')
		if (content != 'E' && content != 'P' && content != 'C')
			exit_error("Map contains invalid characters", NULL);
}

void	check_walls(t_map *map)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (x < map->width)
	{
		if (map->board[0][x] != '1' || map->board[map->height - 1][x] != '1')
			exit_message("map is not surrounded by walls", map);
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (map->board[y][0] != '1' || map->board[y][map->width - 1] != '1')
			exit_message("map is not surrounded by walls", map);
		y++;
	}
}
