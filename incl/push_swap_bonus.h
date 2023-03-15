/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:21 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 18:31:06 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_single;

typedef struct two_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_two;

int			check_and_append(t_two *stack, int *i, char **input);
int			add_back(t_two *lst, t_single *new, int control);
int			add_front(t_two *lst, t_single *new, int control);
void		perform_action(char *command, t_two *stack);
t_two		*arrange_stack(char **input, int amount);
void		parse_input(char *command, t_two *stack);
void		del_first(t_two *stack, int control);
int			check_if_sorted(t_single *stack);
int			check_duplicte(t_single *stack);
int			check_commands(char *command);
void		set_index(t_single *stack);
int			free_stacks(t_two *stack);
t_single	*lstlast(t_single *lst);
int			lstsize(t_single *lst);
t_single	*new_list(int content);
int			precheck(char *str);
int			rra(t_two *stack);
int			rrb(t_two *stack);
int			sb(t_two *stack);
int			ra(t_two *stack);
int			pa(t_two *stack);
int			pb(t_two *stack);
int			rb(t_two *stack);
int			sa(t_two *stack);

#endif