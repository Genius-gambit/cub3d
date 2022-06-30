# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/06/30 16:56:16 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

LIBFT		=	libft.a

LIBFTDIR	=	./libft

GNL			=	get_next_line.a

GNLDIR		=	./get_next_line

SRCS		=	./srcs/main.c ./srcs/parse_file.c ./srcs/errors.c \
				./srcs/utils_parse.c ./srcs/utils_file.c ./srcs/memory_mngmnt.c \
				./srcs/utils_file_ext.c

# MLX			=	libmlx.a

# MLXDIR		=	./minilibx_opengl

# MLXFLG		=	./libmlx.a -framework OpenGL -framework Appkit

OBJS		=	${SRCS:.c=.o}

CC			=	gcc -g3

CFLAGS		=	-Wall -Werror -Wextra

${NAME}:	${OBJS}
			${MAKE} -C ${GNLDIR}
#			${MAKE} -C ${MLXDIR}
			${MAKE} -C ${LIBFTDIR}
			cp ${LIBFTDIR}/${LIBFT} ./
			cp ${GNLDIR}/${GNL} ./
#			cp ${MLXDIR}/${MLX} ./
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${GNL} -o ${NAME} -Ofast

all:	${NAME}

vg:		${NAME}
		valgrind -s --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./cub3d file.cub

clean:
		rm -rf ${OBJS}
		rm -rf ${LIBFT}
		rm -rf ${GNL}
#		rm -rf ${MLX}
		${MAKE} clean -C ${LIBFTDIR}
#		${MAKE} clean -C ${MLXDIR}

fclean:	clean
		${MAKE} fclean -C ${LIBFTDIR}
		${MAKE} fclean -C ${GNLDIR}
		rm -rf ${NAME}

re: fclean all

.PHONY : all clean re fclean