#include "push_swap.h"

static void find_path_to_smaller(int *map, small_stack *stack, int number)
{
	int index = 0;
	small_stack *head;
	int i;
	int size;

	size = lstsize(stack);
	ft_printf("JESTEM liczba ||%i||\n", number);
	i = -1;
	head = stack;
	while (++i < size - 1)
	{
		//if (i == size - 2)
		//	index = size - 1;
		//ft_printf(">>>przed: %i   po: %i<<<",stack->number, stack->next->number);
		if (stack->number > number && stack->next->number < number)
		{
			ft_printf("\n\n.....%i > %i && %i < %i??.......\n\nindex tu: %i", stack->number, number, stack->next->number, number, stack->next->index);
			index = stack->next->index;
		}
		stack = stack->next; 
	}
	stack = head;
	ft_printf("index tu: %i\n", index);
	if (index <= size / 2)
	{
		ft_printf("\n\nindex ze staku b%i\n\n", index);
		map[4] = index;
		map[5] = 0;
	}
	else
	{
		ft_printf("\n\nindex ze stakudddddd b%i & size %i\n\n", index, size);
		map[4] = 0;
		map[5] = size - index;
	}
}

static void find_path_to_max(int *map, small_stack *stack, int max)
{
	int max_index;
	small_stack *head;
	int size = lstsize(stack);
	head = stack;
	while(stack)
	{
		if (stack->number == max)
			max_index = stack->index;
		stack = stack->next;
	}
	stack = head;
	if (max_index < size / 2)
	{
		map[4] = max_index;
		map[5] = 0;
	}
	else
	{
		map[4] = 0;
		map[5] = size - max_index;
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

	ft_printf("checking for %i in stack:\n", node->number);
	print_list(stack->stack_b);
	int size = lstsize(stack->stack_a);
	
	if (node->index < size / 2)
	{
		//ft_printf("EEEEEEEEEEE");
		map[2] = node->index;
		map[3] = 0;
	}
	else
	{
		ft_printf("%i - %i = -1??", size, node->index);
		map[2] = 0;
		map[3] = size - node->index;
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

void send_map(big_stack *container, int *map, int index)
{
	ft_printf("CONTAINER BEFORE:\n");
	print_list(container->stack_a);

	int i;
	small_stack *temp;

	temp = container->stack_a;
	i = -1;

	while (++i < index)
		container->stack_a = container->stack_a->next;
	container->stack_a->map = map;
	container->stack_a = temp;
	ft_printf("CONTAINER AFTER:\n");
	print_list(container->stack_a);
}

void update_map(small_stack *stack, int *map, big_stack *container, int max, int min)
{
	int i;
	small_stack *big_temp;
	big_stack *temp;
	int size;
	int a = -1;

	temp = container;
	size = lstsize(container->stack_a);
ft_printf("~~liczba: %i~~\n", stack->number);
ft_printf("container\n");
print_list(container->stack_b);
	big_temp = container->stack_a;
	while (++a < size)
	{
		int j = -1;
		i = -1;
		while (++i < 6)
			map[i] = 0;
		check_for_steps(temp, stack, max, min, map);
		while (++j < 6)
		{
			ft_printf("%i\n", map[j]);
		}
		send_map(container, map, a);
	}
	container->stack_a = big_temp;
}

void clear_map(int **map)
{
	int j;
	int i;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 6)
			map[i][j] = 0;
	}
}

void print_map(int *map)
{
	int i = -1;
	while (++i < 6)
	{
		if (i == 0)
			ft_printf("rr:	");
		if (i == 1)
			ft_printf("rrr:	");
		if (i == 2)
			ft_printf("ra:	");
		if (i == 3)
			ft_printf("rra:	");
		if (i == 4)
			ft_printf("rb:	");
		if (i == 5)
			ft_printf("rrb:	");
		ft_printf("||%i||\n", map[i]);
	}
}

void turk(big_stack *stack)
{
	//0 - rr	3 - rra
	//1 - rrr	4 - rb
	//2 - ra	5 - rrb

	int max;
	int min;
	int min_or_max;
	int size;
	small_stack *temp;
	int map[4][6];
	int i = -1;
	clear_map(map);
	size = lstsize(stack->stack_a);
	while (++i < 5)
		push_b(stack);
	temp = stack->stack_a;
	ft_printf("stack A przed:\n");
	print_list(stack->stack_a);
	ft_printf("stack B przed:\n");
	print_list(stack->stack_b);
	find_max_and_min(stack->stack_b, &min, &max);
	check_for_steps(stack, temp->next, max, min, map);

		//update_map(stack->stack_a, map, stack, max, min);
	//}
	print_map(map);
	ft_printf("stack A po:\n");
	print_list(stack->stack_a);
	ft_printf("stack B po:\n");
	print_list(stack->stack_b);

	
	//stack->stack_a = temp;
	//temp = stack->stack_a;
	//push_b(stack);
	
	//push_b(stack);
	//find_max_and_min(stack->stack_b, &min, &max);
	free_everything(stack);
}