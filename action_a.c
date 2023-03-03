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

void	push_a(t_two *stack)
{
	if (stack->stack_b)
	{
		add_front(stack, new_list(stack->stack_b->number), 1);
		del_first(stack, 0);
		set_index(stack->stack_a);
		set_index(stack->stack_b);
		ft_printf("pa\n");
	}
}

void	sa(t_two *stack)
{
	t_single	*first;
	t_single	*second;

	first = new_list(stack->stack_a->number);
	second = new_list(stack->stack_a->next->number);
	del_first(stack, 1);
	del_first(stack, 1);
	add_front(stack, first, 1);
	add_front(stack, second, 1);
	set_index(stack->stack_a);
	ft_printf("sa\n");
}

void	move_backwards_a(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_a) > 1)
	{
		head = stack->stack_a->next;
		add_back(stack, new_list(stack->stack_a->number), 1);
		free(stack->stack_a);
		stack->stack_a = head;
		set_index(stack->stack_a);
	}
}

void	move_forward_a(t_two *stack)
{
	t_single	*head;

	head = new_list(lstlast(stack->stack_a)->number);
	add_front(stack, head, 1);
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
