/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:08 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 15:18:11 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	second_case(t_two *stack)
{
	sa(stack);
	move_forward_a(stack);
	ft_printf("sa\n");
	ft_printf("rra\n");
}

static void	third_case(t_two *stack)
{
	move_backwards_a(stack);
	ft_printf("ra\n");
}

static void	fourth_case(t_two *stack)
{
	sa(stack);
	move_backwards_a(stack);
	ft_printf("sa\n");
	ft_printf("ra\n");
}

static void	fifth_case(t_two *stack)
{
	move_forward_a(stack);
	ft_printf("rra\n");
}

void	sort_three(t_two *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->stack_a->number;
	second = stack->stack_a->next->number;
	third = stack->stack_a->next->next->number;
	if (first > second && second < third && first < third && ft_printf("sa\n"))
		sa(stack);
	else if (first > second && second > third)
		second_case(stack);
	else if (first > second && second < third)
		third_case(stack);
	else if (first < second && second > third && first < third)
		fourth_case(stack);
	else if (first < second && second > third)
		fifth_case(stack);
}
