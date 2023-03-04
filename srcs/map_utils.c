/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:29 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/04 21:35:29 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_path(t_map *map)
{
	int	i;
	int	j;
	int	counter;
	int	temp;
	int	map_index;

	map_index = 0;
	counter = INT_MAX;
	i = -1;
	while (++i < 4)
	{
		temp = 0;
		j = -1;
		while (++j < 6)
			temp += map->map[i][j];
		if (temp < counter)
		{
			counter = temp;
			map_index = i;
		}
	}
	update_best_solution(map->map[map_index], map->best_path);
}

int	count_steps(int *map)
{
	int	counter;
	int	i;

	i = -1;
	counter = 0;
	while (++i < 6)
		counter += map[i];
	return (counter);
}

void	update_best_solution(int *best_path, int *best_solution)
{
	int	i;

	ft_bzero(best_solution, 6);
	i = -1;
	while (++i < 6)
		best_solution[i] = best_path[i];
}

void	shorten_way(int **map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		while (map[i][2] > 0 && map[i][4] > 0)
		{
			map[i][0]++;
			map[i][2]--;
			map[i][4]--;
		}
		while (map[i][3] > 0 && map[i][5])
		{
			map[i][1]++;
			map[i][3]--;
			map[i][5]--;
		}
	}
}

int	get_node_index(t_single *node, int number)
{
	while (node)
	{
		if (node->number == number)
			return (node->index);
		node = node->next;
	}
	return (0);
}
