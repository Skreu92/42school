# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etranchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 17:23:40 by etranchi          #+#    #+#              #
#    Updated: 2017/04/10 16:58:00 by etranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFFLAGS=-Wall -Werror -Wextra
EXEC=libft.a
SRC=srcs/
INC=-I includes/

all: $(EXEC)

libft.a: ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ranlib libft.a

ft_putchar.o: $(SRC)ft_putchar.c
	$(CC) -o ft_putchar.o -c $(SRC)ft_putchar.c $(INC) $(CFFLAGS)

ft_putstr.o: $(SRC)ft_putstr.c
	$(CC) -o ft_putstr.o -c $(SRC)ft_putstr.c $(INC) $(CFFLAGS)

ft_strcmp.o: $(SRC)ft_strcmp.c
	$(CC) -o ft_strcmp.o -c $(SRC)ft_strcmp.c $(INC) $(CFFLAGS)

ft_strlen.o: $(SRC)ft_strlen.c
	$(CC) -o ft_strlen.o -c $(SRC)ft_strlen.c $(INC) $(CFFLAGS)

ft_swap.o: $(SRC)ft_swap.c
	$(CC) -o ft_swap.o -c $(SRC)ft_swap.c $(INC) $(CFFLAGS)

clean:
	rm -rf *.o
fclean:
	rm -rf *.o	
	rm -rf $(EXEC)
re:
	make fclean
	make
