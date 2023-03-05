SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libgnl.a
HEADER = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $@ $<

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re