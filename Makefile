# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:24:50 by dulrich           #+#    #+#              #
#    Updated: 2024/02/28 16:33:38 by dulrich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -lX11 -lm -lbsd -lXext -lmlx

LIBFT_DIR	= ./libft 
SRC_DIR		= ./src
INC_DIR		= ./include

SRC			= game.c utils.c utils2.c fill.c checker.c sprites.c rendering.c
OBJ			= $(SRC:%.c=%.o)

LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= -L$(LIBFT_DIR) -lft

HEADERS		= -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re