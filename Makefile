# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 23:03:51 by dramos-p          #+#    #+#              #
#    Updated: 2022/02/06 02:38:01 by dramos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			= 	gcc
FLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-Iincludes
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

SRC			=	src/pipex.c\
				src/error.c\
				src/children.c\
				src/free.c\
				src/ft_calloc.c\
				src/ft_split.c\
				src/ft_strlen.c\
				src/ft_strncmp.c\
				src/ft_strjoin.c\

all: obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(INCLUDE) -o $@

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
