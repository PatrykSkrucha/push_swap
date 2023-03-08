/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/05 00:24:03 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_two	*stack;
	int		guard;

	if (check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (check_if_sorted(argv, argc))
		return (0);
	stack = arrange_stack(argv, argc);
	guard = 0;
	if (lstsize(stack->stack_a) == 2 && ft_printf("sa\n"))
		guard = sa(stack);
	else if (lstsize(stack->stack_a) == 3)
		guard = sort_three(stack);
	else
		guard = big_sort(stack);
	free_stacks(stack);
	if (guard && ft_printf("Malloc failure.\n"))
		return (1);
	return (0);
}
