#include "push_swap.h"

static int find_index(int *fake_sort, int data, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (fake_sort[i] == data)
			return (i);
	}
	return (0);
}

big_stack *arrange_stack(char **input, int amount)
{
	int i;
	big_stack *stack;
	small_stack *temp;
	int size;
	int *arr;

	arr = bubbleSort(input, amount - 1);
	stack = (big_stack*)malloc(sizeof(big_stack));
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < amount)
	{
		temp = new_list(ft_atoi(input[i]), find_index(arr, ft_atoi(input[i]), amount - 1));
		add_back(stack, temp, 1);
	}
	return (stack);
}