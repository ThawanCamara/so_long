/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:50:43 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/26 19:13:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game;
	t_parse		parsed_data;

	parse_game_files(argc, argv, &parsed_data);
	instantiate_game(&game, argv[1], &parsed_data);
	mlx_hook(game.win, 17, 0, end_game, &game);
	mlx_loop(game.mlx);
	end_game(&game);
	return (0);
}
