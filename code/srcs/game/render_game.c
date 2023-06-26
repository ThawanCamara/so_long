/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:35:05 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:44:48 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(void *p)
{
	t_game	*game;

	game = (t_game *) p;
	render_game(game, mlx_put_image_to_window);
	if (game->victory)
		end_game(game);
	return (0);
}

static void	*get_img(t_game *game, int i, int j)
{
	void	*pic;

	if (game->map.content[get_index(i, j, &game->map)] == '1')
		pic = game->img[0];
	if (game->map.content[get_index(i, j, &game->map)] == '0'
		|| game->map.content[get_index(i, j, &game->map)] == 'P')
		pic = game->img[5];
	if (game->map.content[get_index(i, j, &game->map)] == 'C')
		pic = game->img[2];
	if (game->map.content[get_index(i, j, &game->map)] == 'E')
	{
		if (game->map.coin_count > 0)
			pic = game->img[3];
		else
			pic = game->img[4];
	}
	return (pic);
}

void	render_game(void *p, int (*f)(void *, void *, void *, int, int))
{
	t_game	*game;
	size_t	i;
	size_t	j;

	game = (t_game *) p;
	i = 0;
	j = 0;
	while (j < game->map.size_y)
	{
		while (i < game->map.size_x)
		{				
			f(game->mlx, game->win, get_img(game, i, j), img_x * i, j * img_y);
			if (get_index(i, j, &game->map) == (int)game->map.player_index)
				f(game->mlx, game->win, game->img[1], img_x * i, j * img_y);
			i++;
		}
		i = 0;
		j++;
	}
}

void	init_images(void *instance, void *(*f)(void *, char *, int *, int *))
{
	t_game	*game;
	int		x;
	int		y;

	game = instance;
	x = img_x;
	y = img_y;
	game->img = (void **)malloc(6 * sizeof(void *));
	game->img[0] = f(game->mlx, "assets/wall.xpm", &x, &y);
	game->img[1] = f(game->mlx, "assets/player.xpm", &x, &y);
	game->img[2] = f(game->mlx, "assets/coin.xpm", &x, &y);
	game->img[3] = f(game->mlx, "assets/exit_c.xpm", &x, &y);
	game->img[4] = f(game->mlx, "assets/exit_o.xpm", &x, &y);
	game->img[5] = f(game->mlx, "assets/ground.xpm", &x, &y);
}
