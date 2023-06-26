/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:33:40 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:33:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map_content(char *line, t_map *map, int j)
{
	int				i;
	int				index;
	static int		coin_index;

	i = 0;
	while (line[i] != 0 && line[i] != '\n')
	{
		index = get_index(i, j, map);
		map->content[index] = line[i];
		if (line[i] == 'P')
			map->player_index = index;
		if (line[i] == 'E')
			map->exit_index = index;
		if (line[i] == 'C')
			map->coin_pos[coin_index++] = (size_t) index;
		i++;
	}
}

static void	share_data(t_parse *parsed_data, t_map *map)
{
	map->size_x = parsed_data->size_x;
	map->size_y = parsed_data->size_y;
	map->coin_count = parsed_data->coin_count;
}

//Converts a X,Y coordinate to an array index
int	get_index(int x, int y, t_map *map)
{
	return ((y * map->size_x) + x);
}

void	get_coord(int index, t_map *map, int *ox, int *oy)
{
	*oy = index / map->size_x;
	*ox = index - (*oy * map->size_x);
}

void	build_map(char *filename, t_parse *parsed_data, t_map *map)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = parse_map_name(filename);
	share_data(parsed_data, map);
	map->content = (char *)malloc(map->size_x * map->size_y);
	map->coin_pos = (int *)malloc(map->coin_count * sizeof(int));
	i = 0;
	while (i < map->size_y)
	{
		line = get_next_line(fd);
		fill_map_content(line, map, i);
		free(line);
		i++;
	}
	close(fd);
}
