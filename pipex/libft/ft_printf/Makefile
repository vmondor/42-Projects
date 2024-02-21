# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 18:40:08 by vmondor           #+#    #+#              #
#    Updated: 2024/02/20 12:50:04 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##################################
## ARGUMENTS

NAME		= libftprintf.a

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

##################################
## SOURCES

SRC_FILES		= ft_printf.c ft_printf_utils.c \

OBJ_FILES		= ${SRC_FILES:.c=.o}


#################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
