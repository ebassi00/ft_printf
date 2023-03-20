NAME = libftprintf.a
SRCS = ft_printf_utils.c ft_printf.c ft_strlen.c ft_itoa.c \
		ft_strdup.c ft_atoi.c ft_handle_char.c ft_handle_hexa_lower.c \
		ft_handle_hexa_upper.c ft_handle_integer.c ft_handle_percentage.c \
		ft_handle_pointer.c ft_handle_string.c ft_handle_unsigned.c ft_strchr.c \
		ft_uitoa.c ft_printf_utils2.c ft_printf_utils3.c ft_printf_utils4.c
OBJS = $(SRCS:.c=.o)
HDRS = ft_printf.h
FLAGS = -Wall -Wextra -Werror

$(NAME):
		gcc -c -I $(HDRS) $(FLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus : all
all:	$(NAME)

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus