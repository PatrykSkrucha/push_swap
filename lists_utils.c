#include "push_swap.h"

big_stack *arrange_stack(char **input, int amount)
{
	int i;
	big_stack *stack;
	small_stack *temp;
	int size;

	stack = (big_stack*)malloc(sizeof(big_stack));
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < amount)
	{
		temp = new_list(ft_atoi(input[i]));
		add_back(stack, temp, 1);
	}
	return (stack);
}