/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:46 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 17:24:26 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	free_stacks(t_two *stack)
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
	return (0);
}

int	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(map->map[i]);
	}
	free(map->map);
	if (map->best_solution)
		free(map->best_solution);
	if (map->best_path)
		free(map->best_path);
	free(map);
	return (0);
}

int	free_input(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}
