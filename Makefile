# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:33:07 by equiana           #+#    #+#              #
#    Updated: 2019/10/30 23:17:27 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_DIR = ./libft/
LIB = ./libft/libft.a

SRC = main.c read_data.c render.c render_support.c support.c mouse_handler.c event_handler.c

GNL = ./get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o) get_next_line.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $(GNL) $<

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	gcc $(OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
