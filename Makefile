FILES = lists_utils.c sort_three.c turk.c action_a.c \
		action_b.c checkers.c way_to_b.c map_utils.c map_utils2.c \
		way_to_a.c list_utils2.c free_memory.c \

MAIN = ./srcs/push_swap.c
BONUSFILES = ./srcs/checker.c

SOURCES_DIRECTORY = srcs/

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


RESET = \033[0m
YELLOW = \33[1;33m
LIGHT_CYAN=\033[1;36m
LIGHT_GREEN=\033[1;32m
RED=\033[0;31m



all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OFILES) $(OMAIN) $(HEADER) $(LIBFT)
	cc $(FLAGS) $(OFILES) $(OMAIN) $(LIBFT) -o $(PUSH_SWAP)
	@printf "\n$(LIGHT_CYAN)Created executable $(PUSH_SWAP)$(RESET)\n\n"

bonus: $(BONUS)

$(BONUS): $(OBONUS) $(OFILES) $(HEADERBONUS) $(LIBFT)
	cc $(FLAGS) $(OBONUS) $(OFILES) $(LIBFT) -o $(BONUS)
	@printf "\n$(LIGHT_GREEN)Created executable $(BONUS)$(RESET)\n\n"

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft
clean:
	$(RM) $(OFILES) $(OMAIN) $(OBONUS)
	make clean -C libft
	@printf "\n$(YELLOW)Removing object files$(RESET)\n\n"

fclean: clean
	$(RM) $(PUSH_SWAP) $(BONUS)
	make fclean -C libft
	@printf "\n$(RED)Everything cleaned up$(RESET)\n\n"
re: fclean all

.PHONY: all clean fclean re bonus