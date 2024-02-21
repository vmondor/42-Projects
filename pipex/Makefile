# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:28:19 by vmondor           #+#    #+#              #
#    Updated: 2024/02/21 14:44:12 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
# BONUS			= so_long_bonus

CC				= clang
CFLAGS			= -Wall -Werror -Wextra -g3

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

LIBFTPRINTF_DIR	= libft/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a

HEADERS			= $(SRC_PATH)pipex.h


SRC_PATH		= src/
OBJ_PATH		= src/obj/

SRC_FILES		=	main.c				\
					parsing.c			\
					get_path.c			\
					error.c				\

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(LIBFTPRINTF_DIR) -lftprintf

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
