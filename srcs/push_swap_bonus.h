/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:21 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/05 00:24:39 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

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

typedef struct s_map
{
	int	**map;
	int	*best_path;
	int	*best_solution;
}	t_map;

t_single	*new_list(int content);
t_single	*lstlast(t_single *lst);
t_two		*arrange_stack(char **input, int amount);
int			sb(t_two *stack);
int			add_back(t_two *lst, t_single *new, int control);
void		add_front(t_two *lst, t_single *new, int control);
int			lstsize(t_single *lst);
int			rra(t_two *stack);
int			rrb(t_two *stack);
int			ra(t_two *stack);
void		del_first(t_two *stack, int control);
int			pb(t_two *stack);
int			pa(t_two *stack);
int			rb(t_two *stack);
int			sa(t_two *stack);
void		set_index(t_single *stack);
int			check_duplicate(char **input, int amount);
int			check_if_number(char **input, int amount);
int			check_min_max(char **input, int amount);
void		free_stacks(t_two *stack);
void		validate_input(char **argv, int argc);
int			is_sorted_stack(t_single *stack);
int			check_commands(char *command);
void		perform_action(char *command, t_two *stack);
void		parse_input(char *command, t_two *stack);
void		validate_input(char **argv, int argc);

#endif