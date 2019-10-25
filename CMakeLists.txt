cmake_minimum_required(VERSION 3.14)
project(fdf_final C)

set(CMAKE_C_STANDARD 99)

add_executable(fdf_final main.c event_handler.c fdf.h menu.c projection.c read_data.c render.c support.c libft/ft_lstnew.c libft/ft_list_size.c libft/ft_putchar.c libft/ft_strsplit.c libft/ft_putstr get_next_line/get_next_line.c libft/ft_atoi.c
        libft/ft_memcpy.c libft/ft_strchr.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strnew.c libft/ft_strcat.c libft/ft_strsub.c libft/ft_strlen.c)