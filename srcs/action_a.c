/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:11 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 18:06:30 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_two *stack)
{
	if (stack->stack_b)
	{
		if (add_front(stack, new_list(stack->stack_b->number), 1))
			return (1);
		del_first(stack, 0);
		set_index(stack->stack_a);
		set_index(stack->stack_b);
	}
	return (0);
}

int	sa(t_two *stack)
{
	t_single	*first;
	t_single	*second;

	if (lstsize(stack->stack_a) <= 1)
		return (0);
	first = new_list(stack->stack_a->number);
	second = new_list(stack->stack_a->next->number);
	del_first(stack, 1);
	del_first(stack, 1);
	if (add_front(stack, first, 1) || add_front(stack, second, 1))
		return (1);
	set_index(stack->stack_a);
	return (0);
}

int	ra(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_a) > 1)
	{
		head = stack->stack_a->next;
		if (add_back(stack, new_list(stack->stack_a->number), 1))
			return (1);
		free(stack->stack_a);
		stack->stack_a = head;
		set_index(stack->stack_a);
	}
	return (0);
}

int	rra(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_a) > 1)
	{
		head = new_list(lstlast(stack->stack_a)->number);
		if (add_front(stack, head, 1))
			return (1);
		while (stack->stack_a != NULL)
		{
			if (stack->stack_a->next->next == NULL)
			{
				free(stack->stack_a->next);
				stack->stack_a->next = NULL;
			}
			stack->stack_a = stack->stack_a->next;
		}
		stack->stack_a = head;
		set_index(stack->stack_a);
	}
	return (0);
}
