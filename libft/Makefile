# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iruban <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 15:30:29 by iruban            #+#    #+#              #
#    Updated: 2018/11/16 13:02:38 by iruban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = $(wildcard *.c)

OBJECTS = $(FILES:%.c=%.o)

HEADERS = includes

all: $(NAME)


$(NAME):
	gcc -c -Wall -Werror -Wextra $(FILES) -I $(HEADERS)
	ar rc libft.a $(OBJECTS)
	ranlib libft.a

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all
