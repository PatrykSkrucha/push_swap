/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:19 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/04 21:14:03 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	send_to_b(t_map *map, t_two *stack, int min, int max)
{
	clear_map(map->map);
	ft_bzero(map->best_solution, 6);
	find_max_and_min(stack->stack_b, &min, &max);
	best_solution(stack, map);
	read_map_to_b(map->best_solution, stack);
}

static void	send_to_a(t_map *map, t_two *stack)
{
	clear_map(map->map);
	ft_bzero(map->best_solution, 6);
	path_to_a(stack, get_node(stack->stack_b, 0), map->map);
	find_best_path_to_a(map);
	read_map_to_a(map->best_path, stack);
}

static void	ra_or_rra(t_two *stack, int min, int max)
{
	int	index;

	find_max_and_min(stack->stack_a, &min, &max);
	index = get_node_index(stack->stack_a, min);
	if (index <= lstsize(stack->stack_a) / 2)
	{
		while (index > 0)
		{
			ra(stack);
			ft_printf("ra\n");
			index--;
		}
	}
	else
	{
		index = lstsize(stack->stack_a) - index;
		while (index > 0)
		{
			rra(stack);
			ft_printf("rra\n");
			index--;
		}
	}
}

void	*turk(t_two *stack)
{
	int		i;
	int		min;
	int		max;
	t_map	*map;

	min = INT_MIN;
	max = INT_MAX;
	map = new_map();
	if (!map)
		return (NULL);
	i = -1;
	while (++i < 2 && lstsize(stack->stack_a) > 3 && ft_printf("pb\n"))
		pb(stack);
	while (lstsize(stack->stack_a) > 3)
		send_to_b(map, stack, min, max);
	sort_three(stack);
	while (lstsize(stack->stack_b) > 0)
		send_to_a(map, stack);
	ra_or_rra(stack, min, max);
	free_map(map);
	return (NULL);
}
