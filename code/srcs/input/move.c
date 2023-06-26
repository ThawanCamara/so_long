/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:45:40 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:45:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_movement(t_game *game, int mx, int my)
{
	int	target_index;

	target_index = game->map.player_index + my * game->map.size_x + mx;
	if (check_out_of_bounds(target_index, &game->map)
		|| game->map.content[target_index] == '1')
		return (-1);
	ft_printf("Moves: %d\n", ++game->moves);
	return (target_index);
}

static void	check_current_state(t_game *game, int index)
{
	if (game->map.content[index] == 'C')
	{
		game->map.content[index] = '0';
		game->map.coin_count--;
	}
	if (index == (int) game->map.exit_index
		&& game->map.coin_count == 0)
	{
		end_game(game);
	}
}

void	move_player(t_game *game, char dir)
{
	int		mx;
	int		my;
	int		eval;

	mx = 0;
	my = 0;
	if (dir == 'w')
		my = -1;
	if (dir == 'a')
		mx = -1;
	if (dir == 's')
		my = 1;
	if (dir == 'd')
		mx = 1;
	eval = check_movement(game, mx, my);
	if (eval != -1)
		game->map.player_index = eval;
	check_current_state(game, game->map.player_index);
}
