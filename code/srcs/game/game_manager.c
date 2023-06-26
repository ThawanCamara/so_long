/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:35:03 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/26 19:16:17 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	run_solver(t_game *game)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < (int) game->map.coin_count)
		if (!init_solver(&game->map, game->map.coin_pos[i++]))
			result = 1;
	if (!init_solver(&game->map, game->map.exit_index))
		result = 1;
	if (result == 1)
	{
		free(game->map.content);
		free(game->map.coin_pos);
		throw_error("NO SOLUTION", ERROR_SOLVER);
	}
}

void	instantiate_game(t_game *game, char *argv, t_parse *parsed_data)
{
	build_map(argv, parsed_data, &game->map);
	run_solver(game);
	game->mlx = init_window();
	setup_window(game);
	game->victory = 0;
	game->moves = 0;
	init_images(game, mlx_xpm_file_to_image);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

// Linux requires the destroy_display and loop_end to wipe leaks
int	end_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->img[i]);
		i++;
	}
	mlx_destroy_window(game->mlx, game->win);
	free(game->map.coin_pos);
	free(game->map.content);
	free(game->img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
