/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:36 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/04 19:38:00 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_solution(int *path)
{
	int	i;

	i = -1;
	while (++i < 6)
		path[i] = 0;
}

int	*allocate_solution(void)
{
	int	*solution;

	solution = (int *)malloc(sizeof(int) * 6);
	if (!solution)
		return (NULL);
	clear_solution(solution);
	return (solution);
}

int	**allocate_map(void)
{
	int		i;
	int		**map;

	i = -1;
	map = (int **)malloc(sizeof(int *) * 4);
	if (!map)
		return (NULL);
	while (++i < 4)
		map[i] = (int *)malloc(sizeof(int) * 6);
	clear_map(map);
	return (map);
}

void	clear_map(int **map)
{
	int	j;
	int	i;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 6)
			map[i][j] = 0;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(map->map[i]);
	}
	free(map->map);
	free(map->best_solution);
	free(map);
	free(map->best_path);
}
