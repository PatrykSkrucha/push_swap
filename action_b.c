#include "push_swap.h"

void	move_backwards_b(t_two *stack)
{
	t_single	*head;

	if (lstsize(stack->stack_b) > 1)
	{
		head = stack->stack_b->next;
		add_back(stack, new_list(stack->stack_b->number), 0);
		free(stack->stack_b);
		stack->stack_b = head;
		set_index(stack->stack_b);
	}
}

void	move_forward_b(t_two *stack)
{
	t_single	*head;

	head = new_list(lstlast(stack->stack_b)->number);
	add_front(stack, head, 0);

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

void	push_b(t_two *stack)
{
	if (stack->stack_a)
	{
		add_front(stack, new_list(stack->stack_a->number), 0);
		del_first(stack, 1);
		set_index(stack->stack_a);
		set_index(stack->stack_b);
		ft_printf("pb\n");
	}
}

