#include "push_swap.h"

static void find_path_to_smaller(int *map, small_stack *stack, int number)
{
	ft_printf("hello");
}

static void find_path_to_max(int *map, small_stack *stack, int max)
{
	int up_or_down;
	int max_index;
	small_stack *head;
	head = stack;
	while(stack)
	{
		if (stack->number == max)
			max_index = stack->index;
		stack = stack->next;
	}
	stack = head;
	if (max_index < lstsize(stack) / 2)
	{
		map[4] = max_index;
		map[5] = 0;
	}
	else
	{
		map[4] = 0;
		map[5] = lstsize(stack) - max_index;
	}

}

static void find_max_and_min(small_stack *stack, int *min, int *max)
{
	*min = stack->number;
	*max = stack->number;
		while (stack)
		{
			if (*min > stack->number)
				*min = stack->number;
			if (*max < stack->number)
				*max = stack->number;
			stack = stack->next;
		}
}

static void *check_for_steps(big_stack *stack, small_stack *node, int max, int min, int *map)
{
	//0 - rr	3 - rra
	//1 - rrr	4 - rb
	//2 - ra	5 - rrb

	ft_printf("checking for: %i\n\nfrom stack:\n\n", node->number);
	print_list(stack->stack_a);
	ft_printf("in stack:\n");
	print_list(stack->stack_b);
	if (node->index < lstsize(stack->stack_a) / 2)
	{
		ft_printf("||1here %i||",node->index);
		map[2] = node->index;
		map[3] = 0;
	}
	else
	{
		ft_printf("||2here %i||",lstsize(stack->stack_a) - node->index);
		map[2] = 0;
		map[3] = lstsize(stack->stack_a) - node->index;
	}
	if (node->number < min || node->number > max)
	{
		find_path_to_max(map, stack->stack_b, max);
	}
	else
	{
		find_path_to_smaller(map, stack->stack_b, node->number);
	}
}

void turk(big_stack *stack)
{
	int max;
	int min;
	int min_or_max;
	int map[6];
	int i = -1;
	while (++i < 6)
		map[i] = 0;
	ft_printf("%i\n\n", map[2]);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);
	push_b(stack);

	find_max_and_min(stack->stack_b, &min, &max);
	//ft_printf("min: %i max: %i", min, max);
	check_for_steps(stack, stack->stack_a, max, min, map);
	
	//push_b(stack);
	//push_b(stack);
	//find_max_and_min(stack->stack_b, &min, &max);

	i = -1;
	while (++i < 6)
		ft_printf("%i\n", map[i]);
	free_everything(stack);
}