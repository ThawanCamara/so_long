/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:40 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/20 16:23:17 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include "libft.h"
# include "ft_error.h"
# include "ft_keys.h"
# include "ft_parse.h"
# include "ft_map.h"
# include "ft_solver.h"
# include "ft_render.h"
# include "colortag.h"

# ifndef NAME
#  define NAME "PaCman"
# endif

enum e_proportions
{
	img_x = 64,
	img_y = 64,
};

enum e_img_code
{
	WALL = 0,
	PLAYER = 1,
	COIN = 2,
	EXIT_C = 3,
	EXIT_O = 4
};

typedef struct s_game	t_game;

typedef struct s_player	t_player;

struct s_game
{
	void		*mlx;
	void		*win;
	void		**img;
	t_map		map;
	int			victory;
	int			moves;
	int			width;
	int			heigth;
};

void	instantiate_game(t_game *game, char *argv, t_parse *parsed_data);
int		end_game(t_game *game);

void	*init_window(void);
void	*create_window(void *mlx, int size_x, int size_y, char *title);
void	setup_window(t_game *game);

int		key_press(int key, void *p);
void	key_handler(int key, t_game *game);

void	move_player(t_game *game, char dir);

#endif
