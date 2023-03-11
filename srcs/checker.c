/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:34:41 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 18:44:27 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*command;
	t_two	*stack;

	if (argc < 2)
		return (0);
	stack = arrange_stack(argv, argc);
	if (check_duplicte(stack->stack_a) && !free_stacks(stack))
		return (ft_putstr_fd("Error\n", STDERR_FILENO) && 1);
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		parse_input(command, stack);
		free(command);
	}
	if (lstsize(stack->stack_b) == 0 && !check_if_sorted(stack->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stack);
	return (0);
}
