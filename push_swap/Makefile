# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:10:45 by vmondor           #+#    #+#              #
#    Updated: 2024/01/17 18:12:49 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


# OBJ_PATH = obj/

SRC_FILES		= push_swap.c

OBJ_FILES		= $(SRC_FILES:.c=.o)

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
