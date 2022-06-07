NAME = cub3d

GNL_DIR = ./get_next_line

SRCS = srcs/main.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
		${MAKE} -C ${GNL_DIR}
		cp ${GNL_DIR}/gnl.a ./
		${CC} ${CFLAGS} ${OBJS} gnl.a -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}
		rm -rf gnl.a
		${MAKE} clean -C ${GNL_DIR}

fclean:	clean
		rm -rf ${NAME}

re: fclean all