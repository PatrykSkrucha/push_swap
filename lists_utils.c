#include "push_swap.h"

void arrange_stack(char **input, int amount)
{
	int i;
	big_stack *stack;
	small_stack *temp;
	int size;

	stack = (big_stack*)malloc(sizeof(big_stack));
	if (!stack)
		return ;
	i = 0;
	while (++i < amount)
	{
		temp = new_list(ft_atoi(input[i]));
		add_back(stack, temp, 1);
	}
	
	//free(lstlast(stack->stack_a));
	//ft_printf("sizee: %i", lstlast(stack->stack_a)->number);
	//size = lstsize(stack->stack_a);
	//ft_printf("before:");
	//print_list(stack->stack_a);
	
	move_forward_a(stack);
	//print_list(stack->stack_a);
	//add_front(stack->stack_a, lstlast(stack->stack_a));
	//free(lstlast(stack->stack_a));
	
	
	//ft_printf("po: %i\n", stack->stack_a->number);

	//ft_printf("\n\n\n");
	//while (stack!=NULL)
	//{
	//	ft_printf("po: %i\n", stack->stack_a->number);
	//	stack->stack_a->next;
	//}
}