/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:18:08 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/09 16:30:23 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static int	second_case(t_two *stack)
{
	if (sa(stack) || rra(stack))
		return (1);
	ft_printf("sa\n");
	ft_printf("rra\n");
	return (0);
}

static int	third_case(t_two *stack)
{
	if (ra(stack))
		return (1);
	ft_printf("ra\n");
	return (0);
}

static int	fourth_case(t_two *stack)
{
	if (sa(stack) || ra(stack))
		return (1);
	ft_printf("sa\n");
	ft_printf("ra\n");
	return (0);
}

static int	fifth_case(t_two *stack)
{
	if (rra(stack))
		return (1);
	ft_printf("rra\n");
	return (0);
}

int	sort_three(t_two *stack)
{
	int	first;
	int	second;
	int	third;
	int	guard;

	guard = 0;
	first = stack->stack_a->number;
	second = stack->stack_a->next->number;
	third = stack->stack_a->next->next->number;
	if (first > second && second < third && first < third && ft_printf("sa\n"))
		guard = sa(stack);
	else if (first > second && second > third)
		guard = second_case(stack);
	else if (first > second && second < third)
		guard = third_case(stack);
	else if (first < second && second > third && first < third)
		guard = fourth_case(stack);
	else if (first < second && second > third)
		guard = fifth_case(stack);
	return (guard);
}
