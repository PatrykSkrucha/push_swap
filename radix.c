#include "push_swap.h"
#include <sys/wait.h>

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	int stacksize;

	j = 0;
	i = -1;
	while(sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
	{
		stacksize = lstsize(stack->stack_a);
		while (++i <= stacksize && sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
		{
			if (stack->stack_a->number >> j & 1)
			{
				move_backwards_a(stack);
				//ft_printf("\nstack a:\n");
				//print_list(stack->stack_a);
				//sleep(3);
			}
			else
			{

				push_b(stack);
				//ft_printf("\nstack b:\n");
				//print_list(stack->stack_b);
				//sleep(3);
			}
		}
		sleep(3);
		ft_printf("\npo radix:\n");
		ft_printf("\nstack a:\n");
		print_list(stack->stack_a);
		ft_printf("\nstack b:\n");
		print_list(stack->stack_b);
		while (stack->stack_b)
		{
			//if (stack->stack_a && )
			push_a(stack);
		}
			ft_printf("\nstack a:\n");
			print_list(stack->stack_a);
			sleep(3);
		j++;
		i = 0;
	}
	//sleep(1);
	//ft_printf("tu");
	while (sort_check_asc(stack->stack_a, stack))
		push_b(stack);
	while (stack->stack_b)
	{
		push_a(stack);
		ft_printf("\nstack a:\n");
		print_list(stack->stack_a);
		sleep(3);
		//if (stack->stack_a->number < stack->stack_a->next->number)
		//	move_forward_a(stack);
	}
	ft_printf("\npo:\n");
	print_list(stack->stack_a);
}