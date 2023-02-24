#include "push_swap.h"

big_stack *arrange_stack(char **input, int amount)
{
	int i;
	big_stack *stack;
	
	i = 0;
	stack = (big_stack*)malloc(sizeof(big_stack));
	if (!stack)
		return (NULL);
	while (++i < amount)
		add_back(stack, new_list(ft_atoi(input[i])), 1);
	return (stack);
}