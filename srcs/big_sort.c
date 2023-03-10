/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:19 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 19:01:19 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	find_max_and_min(t_single *stack, int *min, int *max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	while (stack)
	{
		if (stack->number < *min)
			*min = stack->number;
		if (stack->number > *max)
			*max = stack->number;
		stack = stack->next;
	}
}

static void	send_to_b(t_map *map, t_two *stack)
{
	int	guard;

	guard = 0;
	clear_map(map->map);
	ft_bzero(map->best_solution, 6);
	best_solution(stack, map);
	read_map_to_b(map->best_solution, stack, &guard);
	if (guard)
	{
		free_stacks(stack);
		free_map(map);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

static void	send_to_a(t_map *map, t_two *stack)
{
	int	guard;

	guard = 0;
	clear_map(map->map);
	ft_bzero(map->best_solution, 6);
	path_to_a(stack, get_node(stack->stack_b, 0), map->map);
	find_best_path_to_a(map);
	read_map_to_a(map->best_path, stack, &guard);
	if (guard)
	{
		free_stacks(stack);
		free_map(map);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

static int	ra_or_rra(t_two *stack, int min, int max)
{
	int	index;

	find_max_and_min(stack->stack_a, &min, &max);
	index = get_node_index(stack->stack_a, min);
	if (index <= lstsize(stack->stack_a) / 2)
	{
		while (index--)
		{
			if (ra(stack))
				return (1);
			ft_printf("ra\n");
		}
	}
	else
	{
		index = lstsize(stack->stack_a) - index;
		while (index--)
		{
			if (rra(stack))
				return (1);
			ft_printf("rra\n");
		}
	}
	return (0);
}

int	big_sort(t_two *stack)
{
	int		min;
	int		max;
	t_map	*map;

	min = INT_MIN;
	max = INT_MAX;
	map = new_map();
	if (!map)
		return (1);
	while (lstsize(stack->stack_a) > 3 && lstsize(stack->stack_b) != 2)
	{
		if (ft_printf("pb\n") && pb(stack))
			return (1);
	}
	while (lstsize(stack->stack_a) > 3)
		send_to_b(map, stack);
	if (sort_three(stack) && !free_map(map))
		return (1);
	while (lstsize(stack->stack_b) > 0)
		send_to_a(map, stack);
	free_map(map);
	if (ra_or_rra(stack, min, max))
		return (1);
	return (0);
}
