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

void	del_first(t_two *stack, int control)
{
	t_single	*head;

	if (control)
	{
		head = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = head;
	}
	else
	{
		head = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = head;
	}
}

void	set_index(t_single *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

t_single	*get_node(t_single *stack, int index)
{
	t_single	*temp;

	temp = stack;
	while (temp->index != index)
		temp = temp->next;
	return (temp);
}

t_map	*new_map(void)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = allocate_map();
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->best_solution = ft_calloc(6, 4);
	new->best_path = ft_calloc(6, 4);
	if (!new->best_path || !new->best_solution)
	{
		free_map(new);
		return (NULL);
	}
	return (new);
}

t_two	*arrange_stack(char **input, int amount)
{
	int		i;
	t_two	*stack;

	i = 0;
	stack = (t_two *)malloc(sizeof(t_two));
	if (!stack)
		exit (EXIT_FAILURE);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	while (++i < amount)
	{
		if (add_back(stack, new_list(ft_atoi(input[i])), 1))
		{
			free_stacks(stack);
			exit (EXIT_FAILURE);
		}
	}
	set_index(stack->stack_a);
	return (stack);
}
