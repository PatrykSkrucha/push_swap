#include "push_swap.h"
#include <sys/wait.h>

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	small_stack *head;

	j = 0;
	i = 0;
	while(sort_check(stack))
	{
		while (++i < size)
		{
			if (stack->stack_a->number & 1 << j)
			{
				//ft_printf("pb: %i\ni: %i\n", stack->stack_a->number, j);
				push_b(stack);

			}
			else
			{
				move_forward_a(stack);
				//ft_printf("rr head: %i\n", stack->stack_a->number);
			}
		}
		ft_printf("stack a:\n");
		print_list(stack->stack_a);
		ft_printf("stack b:\n");
		print_list(stack->stack_b);
		sleep(5);
		while (stack->stack_b)
		{
			size++;
			push_a(stack);
		}
		ft_printf("\nlista:");
		print_list(stack->stack_a);
		//sleep(3);
		j++;
		i = 0;
	}
}