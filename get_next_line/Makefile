NAME = gnl

LIB = gnl.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
		ar -rcs ${LIB} ${OBJS}

all:	${NAME}

clean:
		rm -rf ${OBJS}
		rm -rf ${LIB}

fclean:	clean

re:	fclean all