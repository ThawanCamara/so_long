/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:31 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:54:14 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "so_long.h"

typedef struct s_parse	t_parse;

struct s_parse
{
	size_t		size_x;
	size_t		size_y;
	size_t		player_count;
	size_t		coin_count;
	size_t		exit_count;
};

void		parse_game_files(int argc, char *argv[], t_parse *parsed_data);
void		parse_map(char *filename, t_parse *parsed_data);
int			parse_map_name(char *filename);
int			parse_line_bounds(char *line, int index);
int			parse_line_content(char *line, char *set);
int			parse_line_game_elements(char *line, t_parse *parsed_data);
int			parse_line_shape(char *line, int index, t_parse *parsed_data);

#endif
