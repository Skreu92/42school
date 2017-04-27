# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etranchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 14:14:34 by etranchi          #+#    #+#              #
#    Updated: 2017/04/27 14:14:39 by etranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c\
		ft_read.c\
		ft_check.c\
		ft_init.c\
		ft_create_piece.c\
		ft_solve.c\
		ft_fill_it.c\

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
