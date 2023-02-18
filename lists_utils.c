#include "push_swap.h"

void arrange_stack(char **input, int amount)
{
	int i;
	big_stack *stack;

	stack = (big_stack*)malloc(sizeof(big_stack));
	if (!stack)
		return ;
	i = 0;
	while (++i < amount)
		add_back(stack, new_list(ft_atoi(input[i])), 1);
	while (stack->stack_a)
	{
		ft_printf("%i\n", stack->stack_a->number);
		stack->stack_a = stack->stack_a->next;
	}
}