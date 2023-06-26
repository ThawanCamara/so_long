/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:46:06 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:46:07 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//2 is the index for the first valid line
static int	check_handler(char *line, int index, t_parse *parsed_data)
{
	int	ret;

	if (line == NULL && index == 1)
		return (0);
	else if (line == NULL && index == -1)
		return (1);
	ret = parse_line_bounds(line, index);
	ret += parse_line_content(line, "01PEC");
	if (index == -1)
		ret += parse_line_game_elements(line, parsed_data);
	else
		parse_line_game_elements(line, parsed_data);
	ret += parse_line_shape(line, index, parsed_data);
	return (ret);
}

//i set to -2 at last line, so it becomes -1 which is a flag for last line
static int	check_map_file(int fd, t_parse *parsed_data)
{
	int			i;
	int			ret;
	char		*line;
	char		*next;

	i = 0;
	ret = 0;
	next = NULL;
	while (i >= 0 && ret == 0)
	{
		line = ft_strdup(next);
		free(next);
		next = get_next_line(fd);
		if (next == NULL)
			i = -2;
		parsed_data->size_y++;
		ret = check_handler(line, ++i, parsed_data);
		free(line);
	}
	parsed_data->size_y--;
	return (ft_clean(next, ret));
}

void	parse_map(char *filename, t_parse *parsed_data)
{
	int		fd;

	fd = parse_map_name(filename);
	if (check_map_file(fd, parsed_data) > 0)
		throw_error("INVALID MAP LAYOUT", ERROR_PARSE_MAP);
	close(fd);
}
