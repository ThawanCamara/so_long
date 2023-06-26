/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:46:08 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:49:07 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map_name(char *filename)
{
	int		fd;
	char	*path;

	path = ft_strjoin("maps/", filename);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		throw_error("MAP NOT FOUND", ERROR_PARSE_MAP);
	return (fd);
}

int	parse_line_bounds(char *line, int index)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(line);
	if (line == NULL || line[0] != '1' || line[len - 2] != '1')
		return (1);
	i = 0;
	if (index == 2 || index == -1)
		while (i < len - 1)
			if (line[i++] != '1')
				return (1);
	return (0);
}

int	parse_line_content(char *line, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != 0 && line[i] != '\n')
	{
		while (line[i] != set[j])
			if (set[j++] == 0)
				return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	parse_line_game_elements(char *line, t_parse *parsed_data)
{
	while (*line)
	{
		if (*line == 'P')
			parsed_data->player_count++;
		if (*line == 'E')
			parsed_data->exit_count++;
		if (*line == 'C')
			parsed_data->coin_count++;
		line++;
	}
	return (parsed_data->player_count != 1
		|| parsed_data->exit_count != 1
		|| parsed_data->coin_count == 0);
}

int	parse_line_shape(char *line, int index, t_parse *parsed_data)
{
	size_t	len;
	int		ret;

	len = ft_strlen(line);
	ret = 0;
	if (index == 2)
		parsed_data->size_x = len - 1;
	else
		ret = (len - 1 != parsed_data->size_x);
	return (ret);
}
