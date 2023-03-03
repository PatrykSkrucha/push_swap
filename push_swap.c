#include "push_swap.h"

static void	free_everything(t_two *stack)
{
	t_single	*temp;

	temp = stack->stack_a;
	while (stack->stack_a)
	{
		temp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		free(temp);
	}
	while (stack->stack_b)
	{
		temp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		free(temp);
	}
	free(stack);
}

static t_two	*arrange_stack(char **input, int amount)
{
	int			i;
	t_two	*stack;

	i = 0;
	stack = (t_two *)malloc(sizeof(t_two));
	if (!stack)
		return (NULL);
	while (++i < amount)
		add_back(stack, new_list(ft_atoi(input[i])), 1);
	set_index(stack->stack_a);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_two	*stack;

	if (check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc))
		return (write(1, "Error\n", 6));
	if (check_if_sorted(argv, argc))
		return (0);
	stack = arrange_stack(argv, argc);
	if (lstsize(stack->stack_a) == 2)
		sa(stack);
	else if (lstsize(stack->stack_a) == 3)
		sort_three(stack);
	else
		turk(stack);
	free_everything(stack);
	return (0);
}