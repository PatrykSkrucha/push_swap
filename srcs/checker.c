/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:34:41 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/05 00:26:40 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*command;
	t_two	*stack;

	validate_input(argv, argc);
	stack = arrange_stack(argv, argc);
	command = (char *)malloc(sizeof(char) * 5);
	if (!command)
	{
		free(command);
		return (1);
	}
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		parse_input(command, stack);
		free(command);
	}
	if (is_sorted_stack(stack->stack_a) && lstsize(stack->stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
