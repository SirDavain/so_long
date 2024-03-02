# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:24:50 by dulrich           #+#    #+#              #
#    Updated: 2024/03/02 16:11:02 by dulrich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -lX11 -lm -lbsd -lXext -lmlx

LIBFT_DIR	= libft 
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

SRC			= $(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/utils2.c \
				$(SRC_DIR)/fill.c $(SRC_DIR)/checker.c \
				$(SRC_DIR)/sprites.c $(SRC_DIR)/rendering.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= -L$(LIBFT_DIR) -lft

HEADERS		= -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re
