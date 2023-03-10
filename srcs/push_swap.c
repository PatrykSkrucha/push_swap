/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 17:55:52 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

//static void print_list(t_single *stack)
//{
//	while (stack)
//	{
//		ft_printf("%i\n", stack->number);
//		stack = stack->next;
//	}
//}

int	main(int argc, char **argv)
{
	t_two	*stack;
	int		guard;

	stack = malloc(sizeof(t_two));
	if (!stack && !ft_putstr_fd("Error\n", STDERR_FILENO))
		return (1);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	arrange_stack(argv, argc, stack);
	guard = 0;
	after_checks(stack);
	if (lstsize(stack->stack_a) == 2 && ft_printf("sa\n"))
		guard = sa(stack);
	else if (lstsize(stack->stack_a) == 3)
		guard = sort_three(stack);
	else
		guard = big_sort(stack);
	free_stacks(stack);
	if (guard && !ft_putstr_fd("Error\n", STDERR_FILENO))
		return (1);
	return (0);
}
