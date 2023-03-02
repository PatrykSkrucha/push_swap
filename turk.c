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
	int index;
	int i;
	int size;

	index = 0;
	size = lstsize(stack);
	i = -1;
	while (++i < size - 1)
	{
		if (stack->number > number && stack->next->number < number)
			index = stack->next->index;
		stack = stack->next; 
	}
	map[0][4] = index;							//first_path_a(map, node->index, size);
	map[1][5] = size - index;							//second_path_a(map, node->index, size);
	map[2][5] = size - index;	//third_path_a(map, node->index, size);
	map[3][4] = index;	//fourth_path_a(map, node->index, size);
}

static void find_path_to_max_b(int **map, small_stack *stack, int max)
{
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
static void find_path_to_min_a(small_stack *stack_a, int min, int **map)
{
	int min_index;
	small_stack *head;
	head = stack_a;
	while(stack_a)
	{
		if (stack_a->number == min)
			min_index = stack_a->index;
		stack_a = stack_a->next;
	}
	stack_a = head;;
	map[1][2] = min_index;
	map[3][3] = lstsize(stack_a) - min_index;
}

static void find_path_to_greater(int **map, small_stack *stack_a, int number)
{
	int i;
	int size;
	int index;

	size = lstsize(stack_a);
	index = 0;
	i = -1;
	while (++i < size - 1)
	{
		if (stack_a->number < number && stack_a->next->number > number)
			index = stack_a->next->index;
		stack_a = stack_a->next;
	}
	map[1][2] = index;
	map[3][3] = size - index;
}

static void check_for_steps_to_a(big_stack *stack, small_stack *node, int max, int min, int **map)
{
	if (node->number < min || node->number > max)
		find_path_to_min_a(stack->stack_a, min, map);
	else
		find_path_to_greater(map, stack->stack_a, node->number);
}
static void check_for_steps_to_b(big_stack *stack, small_stack *node, int max, int min, int **map)
{
	map[0][2] = node->index;							//first_path_a(map, node->index, size);
	map[1][2] = node->index;							//second_path_a(map, node->index, size);
	map[2][3] = lstsize(stack->stack_a) - node->index;	//third_path_a(map, node->index, size);
	map[3][3] = lstsize(stack->stack_a) - node->index;	//fourth_path_a(map, node->index, size);
	if (node->number < min || node->number > max)
		find_path_to_max_b(map, stack->stack_b, max);
	else
		find_path_to_smaller(map, stack->stack_b, node->number);
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
		else if (j == 1)
			ft_printf("second path ra rrb:\n");
		else if (j == 2)
			ft_printf("third path rra rrb:\n");
		else if (j == 3)
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

static void send_number_to_b(int *solution, big_stack *stack)
{
	while (solution[0] != 0 && solution[0]--)
	{
		move_backwards_a(stack);
		move_backwards_b(stack);
		ft_printf("rr\n");
	}
	while (solution[1] != 0 && solution[1]--)
	{
		move_forward_a(stack);
		move_forward_b(stack);
		ft_printf("rrr\n");
	}
	while (solution[2] != 0 && solution[2]--)
	{
		ft_printf("ra\n");
		move_backwards_a(stack);
	}
	while (solution[3] != 0 && solution[3]--)
	{
		move_forward_a(stack);
		ft_printf("rra\n");
	}
	while (solution[4] != 0  && solution[4]--)
	{
		move_backwards_b(stack);
		ft_printf("rb\n");
	}
	while (solution[5] != 0 && solution[5]--)
	{
		move_forward_b(stack);
		ft_printf("rrb\n");
	}
	push_b(stack);
}

static void send_number_to_a(int *solution, big_stack *stack)
{
	while (solution[2] != 0 && solution[2]--)
	{
		ft_printf("ra\n");
		move_backwards_a(stack);
	}
	while (solution[3] != 0 && solution[3]--)
	{
		move_forward_a(stack);
		ft_printf("rra\n");
	}
	push_a(stack);

}

static int get_node_index(small_stack *node, int number)
{
	while (node)
	{
		if (node->number == number)
			return (node->index);
		node = node->next;
	}
	return (0);
}

static int *find_best_path_to_a(int **map)
{
	if (map[1][2] <= map[3][3])
		return (map[1]);
	else
		return (map[3]);
}

char *turk(big_stack *stack)
{
	int max;
	int min;
	int i;
	int **map;
	int *best_path;
	int *best_solution;
	int steps;

	best_path = allocate_solution();
	best_solution = allocate_solution();
	map = allocate_map();
	push_b(stack);
	push_b(stack);
	while (lstsize(stack->stack_a) > 3)
	{
		i = -1;
		steps = INT_MAX;
		clear_map(map);
		clear_solution(best_solution);
		find_max_and_min(stack->stack_b, &min, &max);
		while (++i < lstsize(stack->stack_a))
		{
			clear_map(map);
			check_for_steps_to_b(stack, get_node(stack->stack_a, i), max, min, map);
			shorten_way(map);
			best_path = find_best_path(map);
			if (count_steps(best_path) < steps)
			{
				steps = count_steps(best_path);
				update_best_solution(best_path, best_solution);
			}
			clear_solution(best_path);
		}
		send_number_to_b(best_solution, stack);
	}
	sort_three(stack);
	i = 0;
	while (lstsize(stack->stack_b) > 0)
	{	
		steps = INT_MAX;
		clear_map(map);
		clear_solution(best_solution);
		find_max_and_min(stack->stack_a, &min, &max);
		check_for_steps_to_a(stack, get_node(stack->stack_b, 0), max, min, map);
		best_path = find_best_path_to_a(map);
		send_number_to_a(best_path, stack);
	}
	i = -1;
	find_max_and_min(stack->stack_a, &min, &max);
	int index = get_node_index(stack->stack_a, min);
	if (index <= lstsize(stack->stack_a) / 2)
	{
		while (index > 0)
		{
			move_backwards_a(stack);
			ft_printf("ra\n");
			index--;
		}
	}
	else
	{
		index = lstsize(stack->stack_a) - index;
		while (index > 0)
		{
			move_forward_a(stack);
			ft_printf("rra\n");
			index--;
		}
	}
	return (NULL);
}