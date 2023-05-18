/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:47:37 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/23 11:25:13 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	calculate_total_movement(t_map *map)
{
	size_t	moves;

	moves = map->move_count;
	return (moves);
}

void	handle_movement(t_map *map, int dx, int dy)
{
	unsigned int	new_x;
	unsigned int	new_y;

	new_x = map->player->image->instances[0].x + dx;
	new_y = map->player->image->instances[0].y + dy;
	if (!check_collision(new_x, new_y, map))
	{
		map->player->image->instances[0].x = new_x;
		map->player->image->instances[0].y = new_y;
		check_coll(map, new_x, new_y);
		check_exit(new_y, new_x, map);
		map->move_count++;
		ft_printf("Player movements: %i\n", map->move_count / 32);
	}
}

void	key_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		handle_movement(map, 0, -1);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		handle_movement(map, 0, 1);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		handle_movement(map, -1, 0);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		handle_movement(map, 1, 0);
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		free_map(map);
		exit(EXIT_SUCCESS);
	}
}
