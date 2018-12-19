cmake_minimum_required(VERSION 3.12)
project(printf)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)
include_directories(libft)
include_directories(libft/includes)
include_directories(srcs)

add_executable(printf
        includes/ft_printf.h
        libft/includes/libft.h
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_strlen.c
        libft/ft_strnew.c
        libft/ft_swap.c
        libft/ft_memset.c
        libft/ft_strncat.c
        libft/ft_strcat.c
        libft/ft_atoi.c
        libft/Makefile

        srcs/float.c
        srcs/ft_printf.c
        srcs/hex.c

        Makefile
        qwe.c srcs/prec.c srcs/print_number.c libft/ft_strcmp.c srcs/print_o.c srcs/print_x.c srcs/parser.c srcs/check.c)
