# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 13:10:03 by mpicard           #+#    #+#              #
#    Updated: 2019/02/01 13:21:28 by mpicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_strdup.c \
		   	ft_strcat.c \
			ft_strcpy.c \
	 		ft_strncat.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strlcat.c \
			ft_atoi.c \
			ft_memmove.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_strchr.c\
			ft_putendl.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_memalloc.c \
			ft_strnew.c \
			ft_memccpy.c \
			ft_memcmp.c \
			ft_strrchr.c \
			ft_memdel.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_str_is_alpha.c \
			ft_str_is_numeric.c \
			ft_str_is_lowercase.c \
			ft_str_is_printable.c \
			ft_str_is_uppercase.c

FLAGS	=	-g3 -Wall -Werror -Wextra

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): 
	gcc -c $(FLAGS) $(SRC)
	ar -rc $(NAME) $(OBJ)

clean :
		rm -rf $(OBJ)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
