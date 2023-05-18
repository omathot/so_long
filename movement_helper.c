/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:58:09 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 12:40:57 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision(unsigned int x, unsigned int y, t_map *map)
{
	mlx_instance_t	*wall_instance;
	int32_t			i;
	unsigned int	wall_x;
	unsigned int	wall_y;

	i = 0;
	while (i < map->sprites->wall->count)
	{
		wall_instance = &map->sprites->wall->instances[i];
		if (!wall_instance)
			free(wall_instance);
		wall_x = wall_instance->x;
		wall_y = wall_instance->y;
		if (x + map->player->image->width > wall_x
			&& x < wall_x + map->sprites->wall->width
			&& y + map->player->image->height > wall_y
			&& y < wall_y + map->sprites->wall->height)
			return (1);
		i++;
	}
	return (0);
}

void	check_coll(t_map *map, unsigned int x, unsigned int y)
{
	mlx_instance_t	*coll_instance;
	size_t			i;
	unsigned int	coll_x;
	unsigned int	coll_y;

	i = 0;
	while (i < map->coll_total)
	{
		coll_instance = &map->collectible->image->instances[i];
		if (!coll_instance)
		{
			free(coll_instance);
		}
		coll_x = coll_instance->x;
		coll_y = coll_instance->y;
		if (x + map->player->image->width > coll_x
			&& x < coll_x + map->collectible->image->width
			&& y + map->player->image->height > coll_y
			&& y < coll_y + map->collectible->image->height)
		{
			coll_instance->enabled = false;
		}
		i++;
	}
}

void	check_exit(unsigned int y, unsigned int x, t_map *map)
{
	mlx_instance_t	*out;
	mlx_instance_t	*collectible;
	size_t			i;

	i = 0;
	out = &map->sprites->out->instances[0];
	while (i < map->coll_total)
	{
		collectible = &map->collectible->image->instances[i];
		if (collectible->enabled == false)
			i++;
		else
			break ;
	}
	if (i == map->coll_total && (uint32_t)(x + map->player->image->width) >
		(uint32_t)out->x && x < (uint32_t)(out->x + map->sprites->out->width)
		&& (uint32_t)(y + map->player->image->height) > (uint32_t)out->y
		&& y < (uint32_t)(out->y + map->sprites->out->height))
	{
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		free_map(map);
		exit(EXIT_SUCCESS);
	}
}
