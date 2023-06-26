/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:49:44 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:50:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_window(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		throw_error("FAILED AT MLX INITIALIZATION", ERROR_MLX);
	return (mlx);
}

void	setup_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map.size_x * img_x;
	height = game->map.size_y * img_y;
	game->win = create_window(game->mlx, width, height, NAME);
}

void	*create_window(void *mlx, int size_x, int size_y, char *title)
{
	void	*win;

	win = mlx_new_window(mlx, size_x, size_y, title);
	if (win == NULL)
		throw_error("FAILED AT WINDOW CREATION", ERROR_MLX);
	return (win);
}
