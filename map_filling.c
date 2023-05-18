/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:59:14 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/18 15:12:24 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_exit(char **copy, t_map *map, t_Vertex vertex)
{
	t_Vertex	up;
	t_Vertex	down;
	t_Vertex	left;
	t_Vertex	right;

	up.y = vertex.y + 1;
	up.x = vertex.x;
	down.y = vertex.y - 1;
	down.x = vertex.x;
	left.y = vertex.y;
	left.x = vertex.x - 1;
	right.y = vertex.y;
	right.x = vertex.x + 1;
	if (vertex.y < 0 || vertex.y >= map->height
		|| vertex.x < 0 || vertex.x >= map->width)
		return ;
	if (copy[vertex.y][vertex.x] != '1' && copy[vertex.y][vertex.x] != 'X')
		copy[vertex.y][vertex.x] = 'X';
	else
		return ;
	validate_exit(copy, map, up);
	validate_exit(copy, map, down);
	validate_exit(copy, map, left);
	validate_exit(copy, map, right);
}

void	fill_board(char **copy, char **board, t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			copy[y][x] = board[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

char	**copy_board(char **board, t_map *map)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = (char **)ft_calloc(map->height, sizeof(char *));
	if (!copy)
		exit_message("error mallocing copy of board,", map);
	while (i < map->height)
	{
		copy[i] = malloc(map->width * sizeof(char));
		if (!copy[i])
		{
			while (i > 0)
				free(copy[i--]);
			free(copy);
			exit_message("error mallocing rows of copy for board", map);
		}
		i++;
	}
	fill_board(copy, board, map);
	return (copy);
}

void	validate_solvable(char **board, t_map *map, t_Vertex vertex)
{
	char	**copy;
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	copy = copy_board(board, map);
	validate_exit(copy, map, vertex);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
				exit_message("Map is unsolvable", map);
			x++;
		}
		y++;
	}
	while (i < map->height)
		free(copy[i++]);
	free(copy);
}
