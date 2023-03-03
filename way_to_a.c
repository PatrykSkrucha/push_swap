/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_to_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:36 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 17:26:02 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_path_to_min_a(t_single *stack_a, int min, int **map)
{
	int			min_index;
	t_single	*head;

	head = stack_a;
	while (stack_a)
	{
		if (stack_a->number == min)
			min_index = stack_a->index;
		stack_a = stack_a->next;
	}
	stack_a = head;
	map[1][2] = min_index;
	map[3][3] = lstsize(stack_a) - min_index;
}

void	path_to_greater(int **map, t_single *stack_a, int number)
{
	int	i;
	int	size;
	int	index;

	size = lstsize(stack_a);
	index = 0;
	i = -1;
	while (++i < size - 1)
	{
		if (stack_a->number < number && stack_a->next->number > number)
			index = stack_a->next->index;
		stack_a = stack_a->next;
	}
	map[1][2] = index;
	map[3][3] = size - index;
}

void	to_a(t_two *stack, t_single *node, int **map)
{
	int	min;
	int	max;

	min = INT_MIN;
	max = INT_MAX;
	find_max_and_min(stack->stack_a, &min, &max);
	if (node->number < min || node->number > max)
		find_path_to_min_a(stack->stack_a, min, map);
	else
		path_to_greater(map, stack->stack_a, node->number);
}

void	read_map_to_a(int *solution, t_two *stack)
{
	while (solution[2] != 0 && solution[2]--)
	{
		ft_printf("ra\n");
		move_backwards_a(stack);
	}
	while (solution[3] != 0 && solution[3]--)
	{
		move_forward_a(stack);
		ft_printf("rra\n");
	}
	push_a(stack);
	ft_printf("pa\n");
}

int	*find_best_path_to_a(int **map)
{
	if (map[1][2] <= map[3][3])
		return (map[1]);
	else
		return (map[3]);
}
