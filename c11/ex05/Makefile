NAME = do-op

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/main.c ./srcs/aff.c ./srcs/calc.c ./srcs/do_op.c  ./srcs/ft_atoi.c


HEADER = ./includes

OBJ = ${SRCS:.c=.o}

RM = rm -f

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I ./includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
