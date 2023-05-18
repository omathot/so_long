/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:36:43 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/04/20 19:07:24 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	atexit(f);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_message("error malloc map", NULL);
	if (argc != 2)
		exit_message("Usage: so_long <filename>\n", map);
	if (!validate_filename(argv[1], ".ber"))
		exit_message("Invalid file extension.", NULL);
	map = initialize_map(argv[1], map);
	if (!map)
		exit_message("Failed to allocate memory for t_map", map);
	map_window(map);
	free_map(map);
	return (0);
}

char	*update_content(char *content, size_t *content_size,
		size_t *allocated_size, ssize_t bytes_read)
{
	char	*temp;

	if (*content_size + bytes_read >= *allocated_size)
	{
		*allocated_size *= 2;
		temp = ft_realloc(content, *allocated_size);
		if (temp == NULL)
			exit_error("failed realloc while reading", content);
		free(content);
		return (temp);
	}
	return (content);
}

char	*read_map(int fd)
{
	size_t	allocated_size;
	size_t	content_size;
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*content;

	content_size = 0;
	bytes_read = 1;
	allocated_size = BUFFER_SIZE;
	content = (char *)malloc(allocated_size);
	if (content == NULL)
		exit_message("Failed to allocate for read map", NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			exit_error("Error while reading", content);
		content = update_content(content, &content_size,
				&allocated_size, bytes_read);
		ft_memcpy(content + content_size, buffer, bytes_read);
		content_size += bytes_read;
	}
	content[content_size] = '\0';
	return (content);
}

char	*prepare_map(int fd, char ***array, t_map *map)
{
	char	*content;

	content = read_map(fd);
	close(fd);
	if (!content)
		exit_message("Map is empty", map);
	validate_map(content);
	check_whitespace(content);
	*array = ft_split(content, '\n');
	if (!*array)
	{
		free(content);
		exit_message("malloc error in ft_split", map);
	}
	return (content);
}

t_map	*initialize_map(char *path, t_map *map)
{
	int		fd;
	char	*content;
	char	**array;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_message("invalid file", map);
	content = prepare_map(fd, &array, map);
	initialize_map_struct(array, map);
	if (!map)
	{
		free(content);
		exit_message("Error initializing map", map);
	}
	validate_solvable(map->board, map, map->player->pos);
	check_walls(map);
	free(content);
	return (map);
}
