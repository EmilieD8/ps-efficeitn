CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= assign_index.c \
		create_stack.c \
		ft_atoi.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_small.c \
		stack_utils_bis.c \
		stack_utils.c \
		swap.c
		
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all:
	cc -o push_swap $(SRC) 

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re