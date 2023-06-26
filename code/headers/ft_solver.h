/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:37 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:52:38 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVER_H
# define FT_SOLVER_H

# include "so_long.h"

typedef struct s_solver	t_solver;

struct s_solver
{
	int	found;
	int	*is_visited;
};

int	init_solver(t_map *map, int target_index);
int	maze_solver(int start_id, int exit_id, t_map *map, t_solver *solver);
int	check_out_of_bounds(int id, t_map *map);

#endif
