/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:46:02 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:47:36 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_extension(char *argv[])
{
	size_t	len;
	size_t	start;

	len = ft_strlen(argv[1]);
	start = len - 4;
	if (ft_strncmp(argv[1] + start, ".ber", 4))
		throw_error("MAP DESCRIPTION FILE MUST END WITH "
			"\e[38;5;220m.ber\e[0m EXTENSION", ERROR_PARSE_MAP);
}

static void	init_parse_data(t_parse *parsed_data)
{
	parsed_data->size_x = 0;
	parsed_data->size_y = 0;
	parsed_data->player_count = 0;
	parsed_data->exit_count = 0;
	parsed_data->coin_count = 0;
}

void	parse_game_files(int argc, char *argv[], t_parse *parsed_data)
{
	if (argc != 2)
		throw_error("INVALID NUMBER OF ARGUMENTS", ERROR_ARGS);
	parse_extension(argv);
	init_parse_data(parsed_data);
	parse_map(argv[1], parsed_data);
}
