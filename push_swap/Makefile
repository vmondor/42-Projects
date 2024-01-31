# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:10:45 by vmondor           #+#    #+#              #
#    Updated: 2024/01/31 15:25:49 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


OBJ_PATH = obj/
SRC_PATH = ./

SRC_FILES		=	check_input_utils.c	\
					check_input.c		\
					ft_split.c			\
					insert.c			\
					main.c				\
					move_both.c			\
					nodes.c				\
					push_swap_init.c	\
					push.c				\
					reverse_rotate.c	\
					rotate.c			\
					sort_three.c		\
					sort.c				\
					stack_utils.c		\
					swap.c				\
					utils.c

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf *.o $(OBJ_PATH)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
