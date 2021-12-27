# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 17:51:22 by ojauregu          #+#    #+#              #
#    Updated: 2021/12/27 17:51:26 by ojauregu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SERVER   = server
CLIENT   = client

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra -c
NAME     = minitalk

LIBFT	 = libft.a
LIB		 = -L./libft -lft

SERVER_B_OBJ = ft_server_bonus.o
CLIENT_B_OBJ = ft_client_bonus.o
SERVER_OBJ = ft_server.o
CLIENT_OBJ = ft_client.o


all : $(NAME)

$(NAME)	: $(LIBFT) $(SERVER) $(CLIENT)

bonus : 
	make $(SERVER_B) $(CLIENT_B)
	
$(LIBFT)  :
	make -C libft

$(SERVER) : $(SERVER_OBJ) 
	$(CC) $< $(LIB) -o $@
	
$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $< $(LIB) -o $@
	
$(SERVER_B) : $(SERVER_B_OBJ) 
	$(CC) $< $(LIB) -o $@
	
$(CLIENT_B) : $(CLIENT_B_OBJ)
	$(CC) $< $(LIB) -o $@

%.o : %.c
	$(CC) $(FLAGS) $< -o $@ -I. 

clean :
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT)
re: fclean all

.PHONY:        all clean fclean re
