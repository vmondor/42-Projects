# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 19:47:45 by vmondor           #+#    #+#              #
#    Updated: 2023/11/14 15:32:13 by vmondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################
## ARGUMENTS

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

##################################
## SOURCES

SRC_FILES		= ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_strlen \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_strlcpy \
					ft_strlcat \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strncmp \
					ft_memchr \
					ft_memcmp \
					ft_strnstr \
					ft_atoi \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin


OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

#################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	# ${CC} ${OBJ_FILES} -o ${NAME}
	ar rcs ${NAME} ${OBJ_FILES}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
