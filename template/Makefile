# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:28:19 by vmondor           #+#    #+#              #
#    Updated: 2024/03/09 14:50:21 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= projet
BONUS			= projet_bonus

CC				= clang
CFLAGS			= -Wall -Werror -Wextra

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

LIBFTPRINTF_DIR	= libft/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a

HEADERS			= $(SRC_PATH)projet.h
HEADERS_BONUS	= $(SRC_PATH_BONUS)projet_bonus.h


SRC_PATH		= src/
OBJ_PATH		= src/obj/

SRC_PATH_BONUS	= bonus/
OBJ_PATH_BONUS	= bonus/obj/

SRC_FILES		=	main.c					\

SRC_FILES_BONUS	=	main.c					\

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

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c $(HEADERS_BONUS)
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
