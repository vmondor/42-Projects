# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:10:45 by vmondor           #+#    #+#              #
#    Updated: 2024/02/15 14:36:53 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= clang
INCLUDES		= -I/usr/include -Imlx
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFTPRINTF_DIR	= libft/ft_printf
LIBFTPRINTF		= $(LIBFTPRINTF_DIR)/libftprintf.a
CFLAGS			= -Wall -Werror -Wextra -g3
HEADERS			= so_long.h


OBJ_PATH	= obj/
SRC_PATH	= ./

SRC_FILES		=	main.c					\
					get_next_line_utils.c	\
					get_next_line.c			\
					file_to_tab.c			\
					utils.c					\
					error.c					\
					check_map.c				\
					check_map_utils.c		\
					get_items.c				\
					so_long.c				\
					close.c					\
					init_map.c				\
					move.c					\
					move_utils.c			\
					check_exit.c			\
					# so_long_utils.c			\

OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME) -L$(LIBFTPRINTF_DIR) -lftprintf

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

bonus : $(OBJ_PATH) ${BONUS}

# ${BONUS}: ${OBJS_BONUS}
# 	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS}

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f ${NAME}
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re