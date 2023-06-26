/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:45:00 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:45:36 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, void *p)
{
	t_game	*game;

	game = (t_game *) p;
	key_handler(key, game);
	return (0);
}

void	key_handler(int key, t_game *game)
{
	if (key == KEY_ESC)
		end_game(game);
	if (key == KEY_W || key == KEY_ARROW_UP)
		move_player(game, 'w');
	if (key == KEY_A || key == KEY_ARROW_LEFT)
		move_player(game, 'a');
	if (key == KEY_S || key == KEY_ARROW_RIGHT)
		move_player(game, 's');
	if (key == KEY_D || key == KEY_ARROW_DOWN)
		move_player(game, 'd');
}
