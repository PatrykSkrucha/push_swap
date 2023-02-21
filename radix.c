#include "push_swap.h"
#include <sys/wait.h>

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	//small_stack *head;

	//head = stack->stack_a;
	j = 0;
	i = -1;
	int stacksize;
	while(sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
	{
		stacksize = lstsize(stack->stack_a);
		while (++i <= stacksize && sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack)) // tu coś zrobić??
		{
			if (stack->stack_a->number >> j & 1)
			{
				//ft_printf("pb: %i  j: %i\n", stack->stack_a->number, j);
				push_b(stack);

			}
			else
			{
				move_backwards_a(stack);
				//ft_printf("rr. %i \n", stack->stack_a->number);
			}
		}
		ft_printf("stack a:\n");
		print_list(stack->stack_a);
		ft_printf("stack b:\n");
		print_list(stack->stack_b);
		sleep(2);
		while (stack->stack_b)
		{
			push_a(stack);
		}
		//sleep(3);
		ft_printf("stack a:\n");
		print_list(stack->stack_a);
		j++;
		i = 0;
	}
	while (sort_check_asc(stack->stack_a, stack))
	{
		move_forward_a(stack);
		push_b(stack);
	}
	while (stack->stack_b)
		push_a(stack);
	print_list(stack->stack_a);
}