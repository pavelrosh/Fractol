NAME = mlx
# MACFLAGS = -framework OpenGL -framework AppKit -lmlx
WINFLAGS = -L minilibx/ -lmlx -lXext -L/usr/X11/lib -lX11 -lm
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS = src/*.c

all: $(NAME)

$(NAME): 
	@gcc $(SRCS) $(LIBFT) $(WINFLAGS)

clean :
	@rm a.out
	
re: clean
	$(NAME)
	
.PHONY: all clean re