# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edrouot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 12:14:56 by edrouot           #+#    #+#              #
#    Updated: 2023/04/03 12:14:58 by edrouot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
SRCS	= assign_index.c \
	create_stack.c \
	Input.c \
	push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort_small.c \
	sort_big.c \
	swap.c \
	stack_utils.c \
	stack_utils_bis.c
		
$(NAME) : $(SCRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)
	
clean:
	rm -rf $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
