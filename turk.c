#include "push_swap.h"

void shorten_way(int **map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		while (map[i][2] > 0 && map[i][4] > 0)  // ra and rb into rr
		{
			map[i][0]++;
			map[i][2]--;
			map[i][4]--;
		}
		while (map[i][3] > 0 && map[i][5])		// rra and rrb into rrr
		{
			map[i][1]++;
			map[i][3]--;
			map[i][5]--;
		}

	}
}

static void find_path_to_smaller(int **map, small_stack *stack, int number)
{
	int index = 0;
	small_stack *head;
	int i;
	int size;

	size = lstsize(stack);
	//ft_printf("JESTEM liczba ||%i||\n", number);
	i = -1;
	head = stack;
	while (++i < size - 1)
	{
		//if (i == size - 2)
		//	index = size - 1;
		//ft_printf(">>>przed: %i   po: %i<<<",stack->number, stack->next->number);
		if (stack->number > number && stack->next->number < number)
		{
			//ft_printf("\n\n.....%i > %i && %i < %i??.......\n\nindex tu: %i", stack->number, number, stack->next->number, number, stack->next->index);
			index = stack->next->index;
		}
		stack = stack->next; 
	}
	//ft_printf("size%i - index%i = ??", size, index);
	stack = head;
	map[0][4] = index;							//first_path_a(map, node->index, size);
	map[1][5] = size - index;							//second_path_a(map, node->index, size);
	map[2][5] = size - index;	//third_path_a(map, node->index, size);
	map[3][4] = index;	//fourth_path_a(map, node->index, size);
}

static void find_path_to_max(int **map, small_stack *stack, int max)
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
	map[0][4] = max_index;							//first_path_a(map, node->index, size);
	map[1][5] = lstsize(stack) - max_index;							//second_path_a(map, node->index, size);
	map[2][5] = lstsize(stack) - max_index;	//third_path_a(map, node->index, size);
	map[3][4] = max_index;	//fourth_path_a(map, node->index, size);

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

static void check_for_steps(big_stack *stack, small_stack *node, int max, int min, int **map)
{
	int size = lstsize(stack->stack_a);
	
	map[0][2] = node->index;							//first_path_a(map, node->index, size);
	map[1][2] = node->index;							//second_path_a(map, node->index, size);
	map[2][3] = lstsize(stack->stack_a) - node->index;	//third_path_a(map, node->index, size);
	map[3][3] = lstsize(stack->stack_a) - node->index;	//fourth_path_a(map, node->index, size);
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

//void update_map(small_stack *stack, int *map, big_stack *container, int max, int min) //do poprawy
//{
//	int i;
//	small_stack *big_temp;
//	big_stack *temp;
//	int size;
//	int a = -1;

//	temp = container;
//	size = lstsize(container->stack_a);
//ft_printf("~~liczba: %i~~\n", stack->number);
//ft_printf("container\n");
//print_list(container->stack_b);
//	big_temp = container->stack_a;
//	while (++a < size)
//	{
//		int j = -1;
//		i = -1;
//		while (++i < 6)
//			map[i] = 0;
//		check_for_steps(temp, stack, max, min, map);
//		while (++j < 6)
//		{
//			ft_printf("%i\n", map[j]);
//		}
//		send_map(container, map, a);
//	}
//	container->stack_a = big_temp;
//}

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

void print_map(int **map)
{
	int i;
	int j;
	int counter;

	j = -1;
	while (++j < 4)
	{
		counter = 0;
		i = -1;
		if (j == 0)
			ft_printf("first path ra rb:\n");
		if (j == 1)
			ft_printf("second path ra rrb:\n");
		if (j == 2)
			ft_printf("third path rra rrb:\n");
		if (j == 3)
			ft_printf("fourth path rra rb:\n");
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
				ft_printf("rb:+	");
			if (i == 5)
				ft_printf("rrb:	");
			ft_printf("||%i||\n", map[j][i]);
			counter += map[j][i];
		}
		ft_printf("steps in total: %i\n\n", counter);
	}
}

static int **allocate_map()
{
	int		i;
	int	**map;

	i = -1;
	map = (int**)malloc(sizeof(int) * 4);
	if (!map)
		return (NULL);
	while (++i < 4)
	{
		map[i] = (int*)malloc(sizeof(int) *6);
	}
	return (map);
}

static int *find_best_path(int **map)
{
	int	i;
	int j;
	int counter;
	int temp;
	int map_index;

	
	map_index = 0;
	counter = INT_MAX;
	i = -1;
	while (++i < 4)
	{
		temp = 0;
		j = -1;
		while (++j < 6)
			temp += map[i][j];
		if (temp < counter)
		{
			counter = temp;
			map_index = i;
		}
	}
	//ft_printf("\n\nbest path is: >>%i<<\n\n", map_index + 1);
	return (map[map_index]);
}

void print_best_path(int *map)
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
			ft_printf("rb:+	");
		if (i == 5)
			ft_printf("rrb:	");
		ft_printf("||%i||\n", map[i]);	
	}
}

static int count_steps(int *map)
{
	int counter;
	int i;

	i = -1;
	counter = 0;
	while (++i < 6)
		counter += map[i];
	return (counter);
}

static void update_best_solution(int *best_path, int *best_solution)
{
	int i = -1;

	while (++i < 6)
		best_solution[i] = 0;
	i = -1;
	while (++i < 6)
		best_solution[i] = best_path[i];
}

void clear_solution(int *best_solution)
{
	int	i;

	i = -1;
	while (++i < 6)
		best_solution[i] = 0;
}
static int *allocate_solution()
{
	int *best_solution;
	best_solution = (int*)malloc(sizeof(int) * 6);
	if (!best_solution)
		return (NULL);
	clear_solution(best_solution);
	return (best_solution);
}

static void send_number(int *solution, big_stack *stack)
{
	ft_printf("steps for algorithm:\n\n");
	while (solution[0] != 0)
	{
		solution[0]--;
		move_backwards_a(stack);
		move_backwards_b(stack);
		ft_printf("rr\n");
	}
	while (solution[1] != 0)
	{
		solution[1]--;
		move_forward_a(stack);
		move_forward_b(stack);
		ft_printf("rrr\n");
	}
	while (solution[2] != 0)
	{
		solution[2]--;
		move_backwards_a(stack);
		ft_printf("ra\n");
	}
	while (solution[3] != 0)
	{
		solution[3]--;
		move_forward_a(stack);
		ft_printf("rra\n");
	}
	while (solution[4] != 0)
	{
		solution[4]--;
		move_backwards_b(stack);
		ft_printf("rb\n");
	}
	while (solution[5] != 0)
	{
		solution[5]--;
		move_forward_b(stack);
		ft_printf("rrb\n");
	}
	push_b(stack);
	ft_printf("pb\n");
	ft_printf("the end\n\n");
}

char *turk(big_stack *stack)
{
	//0 - rr	3 - rra
	//1 - rrr	4 - rb
	//2 - ra	5 - rrb

	int max;
	int min;
	int i = -1;
	small_stack *tempnode;
	int **map;
	int *best_path;
	int *best_solution;
	int steps;
	best_solution = allocate_solution();
	map = allocate_map();
	//while (++i < 10)
	push_b(stack); //dopisac komende 2x
	push_b(stack);
	ft_printf("stack a before:\n\n");
	print_list(stack->stack_a);
	ft_printf("stack b before:\n\n");
	print_list(stack->stack_b);
	int k = -1;
	int pushed_num;
	while (lstsize(stack->stack_a) > 3)
	{
		i = -1;
		steps = INT_MAX;
		find_max_and_min(stack->stack_b, &min, &max);
		while (++i < lstsize(stack->stack_a))
		{
			clear_map(map);
			tempnode = get_node(stack->stack_a, i);
			//ft_printf("\nnode %i: %i\n", i, tempnode->number);
			check_for_steps(stack, tempnode, max, min, map);
			shorten_way(map);
			//ft_printf("\n\nmap:\n\n");
			//print_map(map);
			best_path = find_best_path(map);
			if (count_steps(best_path) < steps)
			{
				steps = count_steps(best_path);
				pushed_num = tempnode->number;
				//ft_printf("update best path for number: %i\n\n", pushed_num);
				//print_best_path(best_path);
				update_best_solution(best_path, best_solution);
				clear_solution(best_path);
			}
		}
		//ft_printf("best solution for number: %i\n", pushed_num);
		//print_best_path(best_solution);
		send_number(best_solution, stack);
		clear_solution(best_solution);
		//ft_printf("stack a:\n");
		//print_list(stack->stack_a);
		//ft_printf("stack b:\n\n");
		//print_list(stack->stack_b);

	}
	sort_three(stack);
	ft_printf("stack a after:\n\n");
	print_list(stack->stack_a);
	ft_printf("stack b after:\n\n");
	print_list(stack->stack_b);
	
	free_everything(stack);
	return (NULL);
}