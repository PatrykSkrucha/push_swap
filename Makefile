FILES = main.c ps_lists.c lists_utils.c
OFILES = $(FILES:.c=.o)

EMAIN = main

HEADER = push_swap.h

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(EMAIN)

$(EMAIN): $(OFILES) $(HEADER) $(LIBFT)
	cc $(FLAGS) $(OFILES) $(LIBFT) -o $(EMAIN)

$(LIBFT):
	make -C libft
clean:
	$(RM) $(EMAIN)
	make clean -C libft

fclean: clean
	$(RM) $(OFILES)
	make fclean -C libft
re: fclean all

.PHONY: all clean fclean