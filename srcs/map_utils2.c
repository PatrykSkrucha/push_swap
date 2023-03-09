/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:36 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/09 16:30:23 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	**allocate_map(void)
{
	int	i;
	int	**map;
	int	control;

	control = 0;
	i = -1;
	map = (int **)malloc(sizeof(int *) * 4);
	if (!map)
		return (NULL);
	while (++i < 4)
	{
		map[i] = (int *)malloc(sizeof(int) * 6);
		if (!map[i] && control++)
			break ;
	}
	if (control)
	{
		while (i-- <= 0)
			free(map[i]);
		free(map);
		return (NULL);
	}
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
