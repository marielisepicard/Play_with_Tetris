# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 14:16:32 by mpicard           #+#    #+#              #
#    Updated: 2019/02/01 15:07:53 by mpicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c list.c solve.c get_next_line.c check_link.c solve_bis.c \
		fillit_bis.c

OBJ = fillit.o list.o solve.o get_next_line.o check_link.o solve_bis.o \
		fillit_bis.o

all: $(NAME)

$(NAME):	
	make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(OBJ) libft/libft.a -o $(NAME) 

clean: 
	/bin/rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all
