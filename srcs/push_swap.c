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

	if (check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (check_if_sorted(argv, argc))
		return (0);
	stack = arrange_stack(argv, argc);
	if (lstsize(stack->stack_a) == 2)
		sa(stack);
	else if (lstsize(stack->stack_a) == 3)
		sort_three(stack);
	else
		turk(stack);
	free_everything(stack);
	return (0);
}
