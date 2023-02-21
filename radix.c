#include "push_swap.h"
#include <sys/wait.h>

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	int stacksize;

	j = 0;
	i = -1;
	while(sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
	{
		stacksize = lstsize(stack->stack_a);
		while (++i <= stacksize && sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
		{
			if (stack->stack_a->number >> j & 1)
				move_backwards_a(stack);
			else
				push_b(stack);

		}
		while (stack->stack_b)
			push_a(stack);
		j++;
		i = 0;
	}
	while (sort_check_asc(stack->stack_a, stack))
	{
		move_forward_a(stack);
		push_b(stack);
	}
	while (stack->stack_b)
		push_a(stack);
}