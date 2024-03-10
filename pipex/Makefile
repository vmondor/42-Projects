# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:28:19 by vmondor           #+#    #+#              #
#    Updated: 2024/03/07 20:05:05 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
BONUS			= pipex_bonus

CC				= clang
CFLAGS			= -Wall -Werror -Wextra

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

LIBFTPRINTF_DIR	= libft/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a

HEADERS			= $(SRC_PATH)pipex.h


SRC_PATH		= src/
OBJ_PATH		= src/obj/

SRC_PATH_BONUS	= bonus/
OBJ_PATH_BONUS	= bonus/obj/

SRC_FILES		=	main.c					\
					parsing.c				\
					get_path.c				\
					pipex.c					\
					pipex_utils.c			\
					init_values.c			\
					process.c				\
					error.c					\

SRC_FILES_BONUS	=	main.c					\
					get_next_line_utils.c	\
					get_next_line.c			\
					parsing.c				\
					get_path.c				\
					pipex.c					\
					init_values.c			\
					process.c				\
					pipex_utils.c			\
					error.c					\
					here_doc.c				\

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)
OBJS_BONUS		= $(addprefix $(OBJ_PATH_BONUS), $(OBJ_FILES_BONUS))

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

bonus : $(OBJ_PATH_BONUS) ${BONUS}

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH_BONUS):
	mkdir $(OBJ_PATH_BONUS)

$(BONUS): $(LIBFT) $(LIBFTPRINTF) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(BONUS) -L$(LIBFT_DIR) -lft -L$(LIBFTPRINTF_DIR) -lftprintf

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_PATH_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f ${NAME}
	rm -f ${BONUS}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
