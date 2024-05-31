# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 18:36:33 by sganiev           #+#    #+#              #
#    Updated: 2024/05/31 12:53:35 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = push_swap.c
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make -C ./libft -s clean

fclean: clean
	make -C ./libft -s fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBFT), $(NAME)