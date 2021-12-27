NAME = libft.a

SRCS = ft_atoi.c\
	ft_bzero.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	
OBJS		= ${SRCS:.c=.o}


GCC = gcc
RM = rm -f
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			${AR} $(NAME) $(OBJS)

clean:
			${RM} $(OBJS_BONUS) $(OBJS)


fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:        all clean fclean re
