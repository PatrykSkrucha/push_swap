/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:25 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/09 16:30:23 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	rb(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_b) > 1)
	{
		head = stack->stack_b->next;
		if (add_back(stack, new_list(stack->stack_b->number), 0))
			return (1);
		free(stack->stack_b);
		stack->stack_b = head;
		set_index(stack->stack_b);
	}
	return (0);
}

int	sb(t_two *stack)
{
	t_single	*first;
	t_single	*second;

	if (lstsize(stack->stack_b) <= 1)
		return (0);
	first = new_list(stack->stack_b->number);
	second = new_list(stack->stack_b->next->number);
	del_first(stack, 0);
	del_first(stack, 0);
	add_front(stack, first, 0);
	add_front(stack, second, 0);
	set_index(stack->stack_b);
	return (0);
}

int	rrb(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_b) > 1)
	{
		head = new_list(lstlast(stack->stack_b)->number);
		if (add_front(stack, head, 0))
			return (1);
		while (stack->stack_b != NULL)
		{
			if (stack->stack_b->next->next == NULL)
			{
				free(stack->stack_b->next);
				stack->stack_b->next = NULL;
			}
			stack->stack_b = stack->stack_b->next;
		}
		stack->stack_b = head;
		set_index(stack->stack_b);
	}
	return (0);
}

int	pb(t_two *stack)
{
	if (stack->stack_a)
	{
		if (add_front(stack, new_list(stack->stack_a->number), 0))
			return (1);
		del_first(stack, 1);
		set_index(stack->stack_a);
		set_index(stack->stack_b);
	}
	return (0);
}
