/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:21 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 17:55:11 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
t_single	*get_node(t_single *stack, int index);
t_two		*arrange_stack(char **input, int amount, t_two *stack);
int			add_back(t_two *lst, t_single *new, int control);
int			add_front(t_two *lst, t_single *new, int control);
int			lstsize(t_single *lst);
int			rra(t_two *stack);
int			rrb(t_two *stack);
int			ra(t_two *stack);
void		del_first(t_two *stack, int control);
int			pb(t_two *stack);
int			pa(t_two *stack);
int			rb(t_two *stack);
int			sa(t_two *stack);
int			sort_three(t_two *stack);
int			big_sort(t_two *stack);
void		find_best_path(t_map *map);
void		set_index(t_single *stack);
int			check_duplicte(t_single *stack);
int			precheck(char *str);
int			check_if_sorted(t_single *stack);
int			count_steps(int *map);
void		update_best_solution(int *best_path, int *best_solution);
void		best_solution(t_two *stack, t_map *map);
void		read_map_to_b(int *solution, t_two *stack, int *guard);
void		shorten_way(int **map);
void		clear_map(int **map);
int			**allocate_map(void);
t_map		*new_map(void);
void		find_path_to_min_a(t_single *stack_a, int min, int **map);
void		path_to_greater(int **map, t_single *stack_a, int number);
void		path_to_a(t_two *stack, t_single *node, int **map);
void		read_map_to_a(int *solution, t_two *stack, int *guard);
void		find_best_path_to_a(t_map *map);
int			get_node_index(t_single *node, int number);
void		find_max_and_min(t_single *stack, int *min, int *max);
int			free_map(t_map *map);
int			free_stacks(t_two *stack);
int			free_input(char **str);
void		after_checks(t_two *stack);
int			check_and_appent(char **str, t_two *stack, int *j);

#endif