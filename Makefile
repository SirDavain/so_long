# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:24:50 by dulrich           #+#    #+#              #
#    Updated: 2024/02/02 13:51:54 by dulrich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -lX11 -lm -lbsd -lXext -lmlx

LIBFT_DIR	= ./libft 
SRC_DIR		= ./src
INC_DIR		= ./include
#MLX_LIB	= mlx

SRC			= game.c utils.c fill.c checker.c sprites.c
OBJ			= $(SRC:%.c=%.o)

LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= -L$(LIBFT_DIR) -lft

HEADERS		= -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) #$(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re