SRCS			=	ft_printf.c format_handler.c \
					printers.c numbers_handler.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


HEADER = ft_printf.h
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				ar rcs $@ $<

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re