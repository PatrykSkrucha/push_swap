FILES = push_swap.c lists_utils.c sort_three.c turk.c action_a.c \
		action_b.c checkers.c way_to_b.c map_utils.c map_utils2.c \
		way_to_a.c list_utils2.c \

SOURCES_DIRECTORY = srcs/

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(FILES))

OFILES = $(SOURCES:.c=.o)

PUSH_SWAP = push_swap

HEADER = ./srcs/push_swap.h

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OFILES) $(HEADER) $(LIBFT)
	cc $(FLAGS) $(OFILES) $(LIBFT) -o $(PUSH_SWAP)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft
clean:
	$(RM) $(OFILES)
	make clean -C libft

fclean: clean
	$(RM) $(PUSH_SWAP)
	make fclean -C libft
re: fclean all

.PHONY: all clean fclean