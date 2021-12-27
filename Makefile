# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 20:37:54 by ojauregu          #+#    #+#              #
#    Updated: 2021/12/27 21:19:03 by ojauregu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= client
NAME2		= server
NAME3		= client_bonus
NAME4		= server_bonus
C_FILES1	= ft_client.c\
				ft_cli_fonc.c\
				ft_cli_fonc_suite.c
C_FILES2	= ft_server.c\
			  ft_ser_fonc.c\
			 ft_ser_fonc_suite.c
C_FILES3	= ft_client_bonus.c	\
			 ft_cli_fonc_bonus.c\
			 ft_cli_fonc_suite_bonus.c
C_FILES4	= ft_server_bonus.c\
			  ft_ser_fonc_bonus.c\
			  ft_ser_fonc_suite_bonus.c
SRCS1		= $(addprefix srcs/,$(C_FILES1))
SRCS2		= $(addprefix srcs/,$(C_FILES2))
SRCS3		= $(addprefix srcs/,$(C_FILES3))
SRCS4		= $(addprefix srcs/,$(C_FILES4))
OBJS1		= $(SRCS1:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
OBJS3		= $(SRCS3:.c=.o)
OBJS4		= $(SRCS4:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror	\
			  -I ./includes

.c.o:
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
			$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

$(NAME3):	$(OBJS3)
			$(CC) $(CFLAGS) $(OBJS3) -o $(NAME3)

$(NAME4):	$(OBJS4)
			$(CC) $(CFLAGS) $(OBJS4) -o $(NAME4)


bonus:		$(NAME3) $(NAME4)

clean:
			rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)

fclean:		clean
			rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)
re:			fclean all

.PHONY:		all bonus clean fclean re
