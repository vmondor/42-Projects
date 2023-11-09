# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheno <pheno@gmail.com>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 19:47:45 by pheno             #+#    #+#              #
#    Updated: 2023/11/09 01:13:34 by pheno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################
## ARGUMENTS

NAME		= libft.a

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

##################################
## SOURCES

SRC_FILES	= ft_isalpha \
		  main

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

#################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	${CC} ${OBJ_FILES} -o ${NAME}

%.o: ${SRC_FILES}.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
