/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 19:09:17 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int argc, char **argv)
{
	t_two	*stack;
	int		guard;

	stack = arrange_stack(argv, argc);
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
