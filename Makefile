# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/06/21 17:16:49 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

LIBFT		= libft.a

SRCS		= ./srcs/main.c ./srcs/parse_file.c ./srcs/errors.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc -g3

CFLAGS		= -Wall -Werror -Wextra

${NAME}:	${OBJS}
			${MAKE} -C ./libft
			cp ./libft/${LIBFT} ./
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}
		rm -rf ${LIBFT}
		${MAKE} clean -C ./libft

fclean:	clean
		${MAKE} fclean -C ./libft
		rm -rf ${NAME}

re: fclean all

.PHONY : all clean re fclean