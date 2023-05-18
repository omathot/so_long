/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:35:24 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/24 11:20:40 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_sprite
{
	mlx_image_t	*wall;
	mlx_image_t	*path;
	mlx_image_t	*out;
}	t_sprite;

typedef struct s_Vertex
{
	size_t	y;
	size_t	x;
}	t_Vertex;

typedef struct s_player
{
	mlx_image_t		*image;
	t_Vertex		pos;
	size_t			moves_taken;
}	t_player;

typedef struct s_collectible
{
	mlx_image_t		*image;
}	t_collectible;

typedef struct s_map
{
	mlx_t			*mlx;
	char			*map_name;
	char			**board;
	size_t			width;
	size_t			height;
	size_t			size;
	t_player		*player;
	size_t			coll_total;
	t_collectible	*collectible;
	size_t			move_count;
	t_sprite		*sprites;
}	t_map;

//
//////////////////////////////////
//			Starts				//
//////////////////////////////////

int		main(int argc, char *argv[]);
char	*read_map(int fd);

//
//////////////////////////////////
//			Validation			//
//////////////////////////////////

bool	validate_filename(const char *filename, const char *ext);
void	check_whitespace(char *content);
void	validate_map(char *content);
void	check_walls(t_map *map);
void	validate_solvable(char **board, t_map *map, t_Vertex vertex);
void	check_chars(char content);
bool	check_line_lengths(char **board);

//
//////////////////////////////////
//			Initializers		//
//////////////////////////////////

t_map	*initialize_map(char *path, t_map *map);
t_map	*initialize_map_struct(char **array, t_map *map);
void	initialize_player(t_map *map, t_Vertex player_pos);
void	initialize_collectible(t_map *map);
void	initialize_sprites(t_map *map);

//
//////////////////////////////////
//			Movement			//
//////////////////////////////////

int		check_collision(unsigned int x, unsigned int y, t_map *map);
void	check_coll(t_map *map, unsigned int x, unsigned int y);
void	check_exit(unsigned int y, unsigned int x, t_map *map);
void	key_hook(void *param);

//
//////////////////////////////////
//			Graphic				//
//////////////////////////////////

int		map_window(t_map *map);
void	render_image(t_map *map, int x, int y);
void	draw_map(t_map *map);

//
//////////////////////////////////
//			Free-ers			//
//////////////////////////////////

void	free_one(mlx_texture_t *n);
void	free_textures(mlx_texture_t *c, mlx_texture_t *e,
			mlx_texture_t *r, mlx_texture_t *p);
void	exit_error(char *msg, char *to_free);
void	exit_message(char *msg, t_map *map);
void	free_map(t_map *map);

#endif