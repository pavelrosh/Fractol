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

NAME = mlx
MACFLAGS = -framework OpenGL -framework AppKit -lmlx
# WINFLAGS = -L minilibx/ -lmlx -lXext -L/usr/X11/lib -lX11 -lm
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS = src/*.c

all: $(NAME)

$(NAME): 
	@gcc $(SRCS) $(LIBFT) $(MACFLAGS)

clean :
	@rm a.out
	
re: clean
	$(NAME)
	
.PHONY: all clean re
