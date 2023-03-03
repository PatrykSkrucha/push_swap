#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				*map;
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

typedef struct s_min_max
{
	int	min;
	int	max;
}	t_min_max;

t_single	*new_list(int content);
t_single	*lstlast(t_single *lst);
t_single	*get_node(t_single *stack, int index);
void		add_back(t_two *lst, t_single *new, int control);
void		add_front(t_two *lst, t_single *new, int control);
int			lstsize(t_single *lst);
void		move_forward_a(t_two *stack);
void		move_forward_b(t_two *stack);
void		move_backwards_a(t_two *stack);
void		del_first(t_two *stack, int control);
void		push_b(t_two *stack);
void		push_a(t_two *stack);
void		move_backwards_b(t_two *stack);
void		sa(t_two *stack);
void		sort_three(t_two *stack);
char		*turk(t_two *stack);
int			*find_best_path(int **map);
void		set_index(t_single *stack);
int			check_duplicate(char **input, int amount);
int			check_if_number(char **input, int amount);
int			check_if_sorted(char **input, int amount);
int			check_min_max(char **input, int amount);
int			count_steps(int *map);
void		update_best_solution(int *best_path, int *best_solution);
int			*best_solution(t_two *stack, t_min_max *min_max, t_map *map);
void		read_map_to_b(int *solution, t_two *stack);
void		shorten_way(int **map);
void		clear_map(int **map);
void		clear_solution(int *best_solution);
int			*allocate_solution(void);
int			**allocate_map(void);
t_map		*new_map(void);
void		find_path_to_min_a(t_single *stack_a, int min, int **map);
void		path_to_greater(int **map, t_single *stack_a, int number);
void		to_a(t_two *stack, t_single *node, t_min_max *mm, int **map);
void		read_map_to_a(int *solution, t_two *stack);
int			*find_best_path_to_a(int **map);
int			get_node_index(t_single *node, int number);

#endif