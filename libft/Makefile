SRCS			= ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_atoi_long.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

HEADER			= libft.h

PRINTF			= ft_printf/ft_printf.o ft_printf/format_handler.o \
				  ft_printf/numbers_handler.o ft_printf/printers.o \

GET_NEXT_LINE 	= get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \

all:			$(NAME)

$(NAME):			$(OBJS) $(HEADER) $(PRINTF) $(GET_NEXT_LINE)
				ar rcs $@ $(OBJS) $(PRINTF) $(GET_NEXT_LINE)
$(PRINTF):
				make -C ft_printf

$(GET_NEXT_LINE):
				make -C get_next_line

clean:
				$(RM) $(OBJS)
				make clean -C ft_printf
				make clean -C get_next_line

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ft_printf
				make fclean -C get_next_line

re:			fclean $(NAME)

.PHONY:			all clean fclean re