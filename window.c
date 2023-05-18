/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omathot <omathot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:36:47 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 12:41:24 by omathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	last_free(void *param)
{
	t_map	*map;

	map = param;
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
	free_map(map);
	exit(EXIT_SUCCESS);
}

int	map_window(t_map *map)
{
	map->mlx = mlx_init((32 * map->width), (32 * map->height), "test", false);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	initialize_collectible(map);
	initialize_sprites(map);
	draw_map(map);
	mlx_loop_hook(map->mlx, &key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	mlx_close_hook(map->mlx, &last_free, map);
	return (EXIT_SUCCESS);
}

void	initialize_sprites(t_map *map)
{
	mlx_texture_t	*tex_pla;
	mlx_texture_t	*tex_col;
	mlx_texture_t	*tex_w;
	mlx_texture_t	*tex_path;
	mlx_texture_t	*tex_ex;

	map->sprites = malloc(sizeof(t_sprite));
	if (!map->sprites)
		exit_message("error mallocinc map->sprites", map);
	tex_w = mlx_load_png("./images/blocks/grassdirtBlock.png");
	tex_pla = mlx_load_png("./images/blocks/blobRight.png");
	tex_col = mlx_load_png("./images/blocks/coin.png");
	tex_ex = mlx_load_png("./images/blocks/purpleBlock.png");
	tex_path = mlx_load_png("./images/blocks/stoneBlock.png");
	if (!tex_w || !tex_col || !tex_ex || !tex_path || !tex_pla)
		exit_message("Error loading textures", map);
	map->sprites->wall = mlx_texture_to_image(map->mlx, tex_w);
	map->sprites->path = mlx_texture_to_image(map->mlx, tex_path);
	map->sprites->out = mlx_texture_to_image(map->mlx, tex_ex);
	map->player->image = mlx_texture_to_image(map->mlx,
			tex_pla);
	map->collectible->image = mlx_texture_to_image(map->mlx,
			tex_col);
	free_textures(tex_col, tex_ex, tex_path, tex_pla);
	free_one(tex_w);
}
