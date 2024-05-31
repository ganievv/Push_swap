# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 18:36:33 by sganiev           #+#    #+#              #
#    Updated: 2024/05/31 17:51:02 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c check_nums.c ft_atol.c check_err_flag.c \
clean_arr_ptrs.c fill_a_stack.c print_sort_commands.c \

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
	rm -f $(OBJ)

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBFT), $(NAME)