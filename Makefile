FILES = lists_utils.c sort_three.c turk.c action_a.c \
		action_b.c checkers.c way_to_b.c map_utils.c map_utils2.c \
		way_to_a.c list_utils2.c \

SOURCES_DIRECTORY = srcs/

MAIN = ./srcs/push_swap.c

BONUSFILES = ./srcs/checker.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(FILES))

OFILES = $(SOURCES:.c=.o)

OMAIN = $(MAIN:.c=.o)

OBONUS = $(BONUSFILES:.c=.o)

PUSH_SWAP = push_swap

BONUS = checker

HEADER = ./srcs/push_swap.h

HEADERBONUS = ./srcs/push_swap_bonus.h

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OFILES) $(OMAIN) $(HEADER) $(LIBFT)
	cc $(FLAGS) $(OFILES) $(OMAIN) $(LIBFT) -o $(PUSH_SWAP)

bonus: $(BONUS)

$(BONUS): $(OBONUS) $(OFILES) $(HEADERBONUS) $(LIBFT)
	cc $(FLAGS) $(OBONUS) $(OFILES) $(LIBFT) -o $(BONUS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft
clean:
	$(RM) $(OFILES) $(OMAIN)
	make clean -C libft

fclean: clean
	$(RM) $(PUSH_SWAP)
	make fclean -C libft
re: fclean all

.PHONY: all clean fclean