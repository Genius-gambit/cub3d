NAME = cub3d

GNL_DIR = ./get_next_line

LIBFT_DIR = ./libft

SRCS = srcs/main.c

OBJS = ${SRCS:.c=.o}

CC = gcc

# CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
		${MAKE} -C ${LIBFT_DIR}
		cp ${LIBFT_DIR}/libft.a ./
		${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}
		rm -rf libft.a
		${MAKE} clean -C ${LIBFT_DIR}

fclean:	clean
		rm -rf ${NAME}

re: fclean all