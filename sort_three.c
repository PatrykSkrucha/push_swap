#include "push_swap.h"

void sort_three(big_stack *stack)
{
	int first;
	int second;
	int third;

	first = stack->stack_a->number;
	second = stack->stack_a->next->number;
	third = stack->stack_a->next->next->number;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		move_forward_a(stack);
		ft_printf("rra\n");
	}
	else if (first > second && second < third)
	{
		move_backwards_a(stack);
		ft_printf("ra\n");
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		move_backwards_a(stack);
		ft_printf("ra\n");
	}
	else if(first < second && second > third)
	{
		move_forward_a(stack);
		ft_printf("rra\n");
	}
}