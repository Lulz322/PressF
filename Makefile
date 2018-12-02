# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 15:05:10 by ybuhai            #+#    #+#              #
#    Updated: 2018/11/20 14:03:19 by iruban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = backtracking.c map.c readfile.c main.c check.c error.c
OBJECT = $(FILES:%.c=%.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	gcc -c $(FLAGS) $(FILES) -I includes
	gcc -o $(NAME) $(OBJECT) -I libft -L libft/ -lft

all: $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re : fclean all
