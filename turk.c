#include "push_swap.h"


void turk(big_stack *stack)
{
	int max_num_b;
	int min_num_b;
	int min_or_max;


	push_b(stack);
	push_b(stack);
	if (stack->stack_b->number > stack->stack_b->next->number)
	{
		max_num_b = stack->stack_b->number;
		min_num_b = stack->stack_b->next->number;
	}
	else
	{
		min_num_b = stack->stack_b->number;
		max_num_b = stack->stack_b->next->number;
	}

	ft_printf("max num: %i\nmin num: %i", max_num_b, min_num_b);
	free_everything(stack);
}