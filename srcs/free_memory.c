/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:46 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/05 00:24:32 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_everything(t_two *stack)
{
	t_single	*temp;

	temp = stack->stack_a;
	while (stack->stack_a)
	{
		temp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		free(temp);
	}
	while (stack->stack_b)
	{
		temp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		free(temp);
	}
	free(stack);
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
