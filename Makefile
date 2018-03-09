# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 12:14:09 by proshchy          #+#    #+#              #
#    Updated: 2018/03/05 12:14:15 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = src/main.c \
src/burning_ship.c \
src/draw.c \
src/infin_cube.c \
src/julia.c \
src/key_hook.c \
src/key_hook_1.c \
src/mandelbrot.c \
src/newton.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -O3 -pthread
GFLAGS = -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): lib $(OBJ)
	@gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c fractol.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

lib:
	make -C libft
normin:
	norminette $(SRC)

.PHONY: all clean re lib










