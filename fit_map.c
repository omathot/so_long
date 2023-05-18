/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:33:21 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/17 22:48:10 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_collectible(t_map *map)
{
	map->collectible = malloc(sizeof(t_collectible));
	if (!map->collectible)
		exit_message("error mallocing collectibles", map);
}

void	render_image(t_map *map, int x, int y)
{
	if (map->board[y][x] == '1')
		mlx_image_to_window(map->mlx, map->sprites->wall, (x * 32), (y * 32));
	else if (map->board[y][x] == '0')
		mlx_image_to_window(map->mlx, map->sprites->path, (x * 32), (y * 32));
	else if (map->board[y][x] == 'C')
	{
		mlx_image_to_window(map->mlx, map->sprites->path, (x * 32), (y * 32));
		mlx_image_to_window(map->mlx, map->collectible->image,
			(x * 32), (y * 32));
	}
	else if (map->board[y][x] == 'E')
		mlx_image_to_window(map->mlx, map->sprites->out, (x * 32), (y * 32));
	else if (map->board[y][x] == 'P')
	{
		mlx_image_to_window(map->mlx, map->sprites->path, (x * 32), (y * 32));
		mlx_image_to_window(map->mlx, map->player->image, (x * 32), (y * 32));
		mlx_set_instance_depth(map->player->image->instances, map->size);
	}
	else
		exit_message("error displaying textures", map);
}

void	draw_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->board[y])
	{
		while (map->board[y][x])
		{
			render_image(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	free_textures(mlx_texture_t *c, mlx_texture_t *e,
		mlx_texture_t *r, mlx_texture_t *p)
{
	mlx_delete_texture(c);
	mlx_delete_texture(e);
	mlx_delete_texture(r);
	mlx_delete_texture(p);
}

void	free_one(mlx_texture_t *n)
{
	mlx_delete_texture(n);
}
