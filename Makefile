# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:24:50 by dulrich           #+#    #+#              #
#    Updated: 2024/02/01 14:33:26 by dulrich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -lX11 -lm -lbsd -lXext -lmlx

LIBFT_DIR	= ./libft 
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
MLX_DIR		= mlx

SRC			= game.c utils.c fill.c checker.c sprites.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= -L$(LIBFT_DIR) -lft

HEADERS		= -I$(INC_DIR) -I$(LIBFT_DIR)-I$(MLX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re