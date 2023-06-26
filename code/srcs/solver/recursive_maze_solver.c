/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_maze_solver.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:49:20 by tde-souz          #+#    #+#             */
/*   Updated: 2023/06/26 19:01:36 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_solver(t_map *map, int target_index)
{
	size_t		i;
	int			ret;
	t_solver	solver;

	solver.is_visited = (int *)malloc(map->size_x * map->size_y * sizeof(int));
	solver.found = 0;
	i = 0;
	while (i < (map->size_x * map->size_y))
	{
		solver.is_visited[i] = 0;
		i++;
	}
	ret = maze_solver(map->player_index, target_index, map, &solver);
	free(solver.is_visited);
	return (ret);
}

int	check_out_of_bounds(int id, t_map *map)
{
	int		ret;

	ret = 0;
	if (id < 0 || id >= (int)(map->size_x * map->size_y))
		ret = 1;
	return (ret);
}

int	maze_solver(int start_id, int exit_id, t_map *map, t_solver *solver)
{
	int	sum;

	if (check_out_of_bounds(start_id, map) || solver->found)
		return (0);
	if (map->content[start_id] == '1'
		|| solver->is_visited[start_id] == 1)
	{
		solver->is_visited[start_id] = 1;
		return (0);
	}
	if (start_id == exit_id)
	{
		solver->found = 1;
		return (1);
	}
	solver->is_visited[start_id] = 1;
	sum = 0;
	sum += maze_solver(start_id - map->size_x, exit_id, map, solver);
	sum += maze_solver(start_id - 1, exit_id, map, solver);
	sum += maze_solver(start_id + 1, exit_id, map, solver);
	sum += maze_solver(start_id + map->size_x, exit_id, map, solver);
	return (sum);
}
