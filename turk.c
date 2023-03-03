#include "push_swap.h"

static void	find_max_and_min(t_single *stack, t_min_max *min_max)
{
	min_max->min = stack->number;
	min_max->max = stack->number;

	while (stack)
	{
		if (min_max->min > stack->number)
			min_max->min = stack->number;
		if (min_max->max < stack->number)
			min_max->max = stack->number;
		stack = stack->next;
	}
}

static void	send_to_b(t_map *map, t_two *stack, t_min_max *min_max)
{
	clear_map(map->map);
	clear_solution(map->best_solution);
	find_max_and_min(stack->stack_b, min_max);
	map->best_solution = best_solution(stack, min_max, map);
	read_map_to_b(map->best_solution, stack);
}

void	send_to_a(t_map *map, t_two *stack, t_min_max *min_max)
{
	clear_map(map->map);
	clear_solution(map->best_solution);
	find_max_and_min(stack->stack_a, min_max);
	to_a(stack, get_node(stack->stack_b, 0), min_max, map->map);
	map->best_path = find_best_path_to_a(map->map);
	read_map_to_a(map->best_path, stack);
}

static void	ra_or_rra(t_two *stack, t_min_max *min_max)
{
	int	index;

	index = get_node_index(stack->stack_a, min_max->min);
	find_max_and_min(stack->stack_a, min_max);
	if (index <= lstsize(stack->stack_a) / 2)
	{
		while (index > 0)
		{
			move_backwards_a(stack);
			ft_printf("ra\n");
			index--;
		}
	}
	else
	{
		index = lstsize(stack->stack_a) - index;
		while (index > 0)
		{
			move_forward_a(stack);
			ft_printf("rra\n");
			index--;
		}
	}
}

char	*turk(t_two *stack)
{
	int			i;
	t_min_max	*min_max;
	t_map		*map;

	map = new_map();
	if (!map)
		return (NULL);
	min_max = (t_min_max *)malloc(sizeof(t_min_max));
	if (!min_max)
		return (NULL);
	i = -1;
	while (++i < 2 && lstsize(stack->stack_a) > 3)
		push_b(stack);
	while (lstsize(stack->stack_a) > 3)
		send_to_b(map, stack, min_max);
	sort_three(stack);
	while (lstsize(stack->stack_b) > 0)
		send_to_a(map, stack, min_max);
	ra_or_rra(stack, min_max);
	return (NULL);
}