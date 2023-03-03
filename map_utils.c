#include "push_swap.h"

int	*find_best_path(int **map)
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
			temp += map[i][j];
		if (temp < counter)
		{
			counter = temp;
			map_index = i;
		}
	}
	return (map[map_index]);
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
	int i = -1;

	while (++i < 6)
		best_solution[i] = 0;
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