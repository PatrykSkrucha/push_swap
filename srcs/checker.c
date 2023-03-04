/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:34:41 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/04 23:33:35 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap_bonus.h"



void	perform_action(char *input, int *control)
{
	if (ft_strlen(input) == 3 && !ft_strncmp(input, "sa\n", 3))
		ft_printf("SA");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "sb\n", 3))
		ft_printf("SB");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "ss\n", 3))
		ft_printf("SS");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "pa\n", 3))
		ft_printf("PA");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "pb\n", 3))
		ft_printf("PB");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "ra\n", 3))
		ft_printf("RA");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rb\n", 3))
		ft_printf("RB");
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rr\n", 3))
		ft_printf("RR");
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rra\n", 3))
		ft_printf("RRA");
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrb\n", 3))
		ft_printf("RRB");
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrr\n", 3))
		ft_printf("RRR");
	else
		*control = 0;
}

int main(void)
{
	//char	*input;
	//size_t	amount;
	//t_two	*stack;
	//int		valid_command;

	//amount = 1;
	//valid_command = 1;
	//input = malloc(5);
	//arrange_stack(argv, argc);
	//while (amount > 0 && valid_command)
	//{
	//	amount = read(0, input, 4);
	//	input[amount] = '\0';
	//	if (!amount)
	//		break ;
	//	perform_action(input, &valid_command);
	//}
	//if (valid_command == 0)
	//{
	//	ft_printf("Error\n");
	//	return (0);
	//}
	ft_printf("jeszcze tu");
	return (0);
}