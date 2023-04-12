# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 16:21:34 by manujime          #+#    #+#              #
#    Updated: 2023/04/12 18:47:01 by manujime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a

SRC =   main.c \
		map_loader.c \
		map_check.c \
		utils.c \
		path.c \

OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/manujime/.brew/opt/glfw/lib/" -o $(NAME)

$(LIBFT):
	make extra -C libft

$(MLX42):
	make -C MLX42/
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C MLX42/

re: fclean all

py:	all

.PHONY: all clean fclean re
