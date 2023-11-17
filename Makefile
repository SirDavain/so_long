NAME = so_long.a

SRC = game.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = 
endif

ifeq ($(shell uname), Linux)
	MLX_LIB = libmlx_$(UNAME).a
else
	MLX_DIR = ./mlx
	MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
	$(MLX_LIB):
		@make -C $(MLX_DIR)
endif

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re


