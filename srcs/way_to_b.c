/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_to_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:52 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/09 16:30:23 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	find_path_to_max_b(int **map, t_single *stack, int max)
{
	int			max_index;
	t_single	*head;

	head = stack;
	while (stack)
	{
		if (stack->number == max)
			max_index = stack->index;
		stack = stack->next;
	}
	stack = head;
	map[0][4] = max_index;
	map[1][5] = lstsize(stack) - max_index;
	map[2][5] = lstsize(stack) - max_index;
	map[3][4] = max_index;
}

static void	find_path_to_smaller(int **map, t_single *stack, int number)
{
	int	index;
	int	i;
	int	size;

	index = 0;
	size = lstsize(stack);
	i = -1;
	while (++i < size - 1)
	{
		if (stack->number > number && stack->next->number < number)
			index = stack->next->index;
		stack = stack->next;
	}
	map[0][4] = index;
	map[1][5] = size - index;
	map[2][5] = size - index;
	map[3][4] = index;
}

static void	check_paths(t_two *stack, t_single *node, int **map)
{
	int	min;
	int	max;

	min = INT_MIN;
	max = INT_MAX;
	find_max_and_min(stack->stack_b, &min, &max);
	map[0][2] = node->index;
	map[1][2] = node->index;
	map[2][3] = lstsize(stack->stack_a) - node->index;
	map[3][3] = lstsize(stack->stack_a) - node->index;
	if (node->number < min || node->number > max)
		find_path_to_max_b(map, stack->stack_b, max);
	else
		find_path_to_smaller(map, stack->stack_b, node->number);
}

void	read_map_to_b(int *solution, t_two *stack, int *guard)
{
	while (solution[0] != 0 && solution[0]-- && ft_printf("rr\n"))
	{
		*guard = ra(stack);
		*guard = rb(stack);
	}
	while (solution[1] != 0 && solution[1]-- && ft_printf("rrr\n"))
	{
		*guard = rra(stack);
		*guard = rrb(stack);
	}
	while (solution[2] != 0 && solution[2]-- && ft_printf("ra\n"))
		*guard = ra(stack);
	while (solution[3] != 0 && solution[3]-- && ft_printf("rra\n"))
		*guard = rra(stack);
	while (solution[4] != 0 && solution[4]-- && ft_printf("rb\n"))
		*guard = rb(stack);
	while (solution[5] != 0 && solution[5]-- && ft_printf("rrb\n"))
		*guard = rrb(stack);
	*guard = pb(stack);
	ft_printf("pb\n");
}

void	best_solution(t_two *stack, t_map *map)
{
	int	i;
	int	steps;

	i = -1;
	steps = INT_MAX;
	while (++i < lstsize(stack->stack_a))
	{
		clear_map(map->map);
		check_paths(stack, get_node(stack->stack_a, i), map->map);
		shorten_way(map->map);
		find_best_path(map);
		if (count_steps(map->best_path) < steps)
		{
			steps = count_steps(map->best_path);
			update_best_solution(map->best_path, map->best_solution);
		}
		ft_bzero(map->best_path, 6);
	}
}
