/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:29 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:53:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "so_long.h"

typedef struct s_map	t_map;

struct s_map
{
	size_t		size_x;
	size_t		size_y;
	char		*content;
	int			*coin_pos;
	size_t		exit_index;
	size_t		player_index;
	size_t		coin_count;
};

void	build_map(char *filename, t_parse *parsed_data, t_map *map);
int		get_index(int x, int y, t_map *map);

#endif
