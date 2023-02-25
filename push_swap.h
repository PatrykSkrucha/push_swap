#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <limits.h>

typedef struct s_stack
{
	int				number;
	unsigned	int	index;
	int				*map;
	struct s_stack	*next;
}	small_stack;

typedef struct two_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	big_stack;


small_stack	*new_list(int content);
void print_list(small_stack *lst);
small_stack	*lstlast(small_stack *lst);
void	add_back(big_stack *lst, small_stack *new, int control);
void	add_front(big_stack *lst, small_stack *new, int control);
int	lstsize(small_stack  *lst);
big_stack *arrange_stack(char **input, int amount);
void move_forward_a(big_stack *stack);
void move_forward_b(big_stack *stack);
void move_backwards_a(big_stack *stack);
void del_first(big_stack *stack, int control);
void push_b(big_stack *stack);
void push_a(big_stack *stack);
int sort_check_desc(small_stack *stack);
int sort_check_asc(small_stack *stack, big_stack *container);
void free_everything(big_stack *stack);
void move_backwards_b(big_stack *stack);
void sa(big_stack *stack);
void sort_three(big_stack *stack);
void turk(big_stack *stack);
void set_index(small_stack *stack);

#endif