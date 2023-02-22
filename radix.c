#include "push_swap.h"
#include <sys/wait.h>

int check_if_ra(big_stack *stack)
{
	if (stack->stack_b->next && stack->stack_b->number < 0 
		&& stack->stack_b->next->number >= 0)
			return (1);
	return (0);
}

void radix(big_stack *stack, int size)
{
	int i;
	int j;
	int stacksize;

	j = 0;
	i = -1;
	while(sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack))
	{
		// && sort_check_desc(stack->stack_a) && sort_check_asc(stack->stack_a, stack)
		stacksize = lstsize(stack->stack_a);
		while (++i <= stacksize)
		{
			if (!sort_check_asc(stack->stack_a, stack))
			{
				print_list(stack->stack_a);
				exit(0);
			}
			if ((stack->stack_a->number >= 0 && stack->stack_a->number >> j & 1)
				|| (stack->stack_a->number < 0 
				&& (stack->stack_a->number * -1) >> j & 1))
				{
					push_b(stack);
					if (stack->stack_b->next && (stack->stack_b->number > stack->stack_b->next->number))
						move_backwards_b(stack);
				}
			else
				move_backwards_a(stack);
		}
		sleep(3);
		ft_printf("------------------------------");
		ft_printf("\npo radix i:%i:\n",j);
		ft_printf("\nstack a:\n");
		print_list(stack->stack_a);
		ft_printf("\nstack b:\n");
		print_list(stack->stack_b);
		ft_printf("------------------------------");
		while (stack->stack_b)
		{
			push_a(stack);
			if (stack->stack_a->next && stack->stack_a->number > 0
				&& stack->stack_a->next->number <= 0)
			{
				move_backwards_a(stack);
			}
			if (!sort_check_asc(stack->stack_a, stack))
			{
				print_list(stack->stack_a);
				exit(0);
			}
		}
		ft_printf("\nstack a:\n");
		print_list(stack->stack_a);
		sleep(3);
		j++;
		i = 0;
	}
	while (sort_check_asc(stack->stack_a, stack) || (lstsize(stack->stack_a) > 1))
	{
		//ft_printf("\nstack a:\n");
		//print_list(stack->stack_a);
		//ft_printf("\nstack b:\n");
		//print_list(stack->stack_b);
		//sleep(3);
		//if((stack->stack_a->number < stack->stack_a->next->number))
		//	move_backwards_a(stack);
		//else
		//{
			push_b(stack);
	//		if (stack->stack_b && stack->stack_b->number < 0)
	//			{
					
	//ft_printf("ha");
	//				move_backwards_b(stack);
	//			}
	//	}
	}
	while (stack->stack_b)
	{
		push_a(stack);
		move_backwards_a(stack);
		//ft_printf("\nstaaack a:\n");
		//print_list(stack->stack_a);
		//sleep(1);
		
	}
	ft_printf("\npo:\n");
	print_list(stack->stack_a);
}