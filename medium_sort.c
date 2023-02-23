#include "push_swap.h"

void medium_sort(big_stack *stack)
{
	int max_index;

	max_index = max_index = lstsize(stack->stack_a) - 1;
	//ft_printf("max %i", max_index);
	while (lstsize(stack->stack_a) != 3)
	{
		//ft_printf("hopla");
		push_b(stack);
	}
	sort_three(stack);
	if (stack->stack_b->next->index == max_index)
		move_backwards_b(stack);
	//ft_printf("stack a:\n");
	//print_list(stack->stack_a);
	while (stack->stack_b)
	{
		push_a(stack);
		if (stack->stack_a->index == max_index)
			move_backwards_a(stack);
		while (stack->stack_a->number > stack->stack_a->next->number)
		{
			sa(stack);
				if (stack->stack_a->next->number > stack->stack_a->next->next->number)
					move_backwards_a(stack);
		}
		while (sort_check_asc(stack->stack_a, stack))
		{
			//sleep(1);
			move_backwards_a(stack);
		}
	}
	//ft_printf("here stack: \n");
	//print_list(stack->stack_a);
	//sleep(5);
	//print_list(stack->stack_a);
}