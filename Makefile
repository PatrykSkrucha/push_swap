FILES = push_swap.c ps_lists.c sort_three.c turk.c
OFILES = $(FILES:.c=.o)

PUSH_SWAP = push_swap

HEADER = push_swap.h

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