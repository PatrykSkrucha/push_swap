#include "push_swap.h"
#include <sys/wait.h>

static int max_bit(small_stack *stack)
{
	int max;
	int bits;

	bits = 1;
	max = stack->number;
	while (stack)
	{
		if (stack->number > max || ((stack->number * -1) > max))
			max = stack->number;
		if (max < 0)
			max *= -1;
		stack = stack->next;
	}
	//ft_printf("max: %i\n", max);
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
	max_bits = max_bit(stack->stack_a);
	j = 0;
	//ft_printf("max bit: %i", max_bits);
	while(++a < max_bits)
	{
		i = 0;
		while (++i < size && sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
		{
			if (stack->stack_a->index >> j & 1)
				move_backwards_a(stack);
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