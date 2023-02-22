#include "push_swap.h"
#include <sys/wait.h>

int max_bit(big_stack *stack)
{
	int max;
	int bits;

	bits = 1;
	max = stack->stack_a->number;
	while (stack->stack_a)
	{
		if (stack->stack_a->number > max)
			max = stack->stack_a->number;
		stack->stack_a = stack->stack_a->next;
	}

	while (max != 1 && max != -1)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	int max_bits;
	int a;

	a = -1;
	max_bits = max_bit(stack);
	j = 0;
	print_list(stack->stack_a);
	while(++a < max_bits)
	{
		i = 0;
		while (++i < size)
		{
			if (stack->stack_a->index >> j & 1)
				{
				
				move_backwards_a(stack);
				}
			else
				push_b(stack);

		}
		while (stack->stack_b)
			push_a(stack);
		j++;
	}
	while (stack->stack_b)
	{
		move_forward_a(stack);
		push_b(stack);
	}
	while (stack->stack_b)
		push_a(stack);
}