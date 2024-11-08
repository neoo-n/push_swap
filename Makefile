CC = cc
FLAGS = -Wall -Wextra -Werror 
SRC = 
OBJ = ${SRC:.c=.o}
NAME = push_swap
RM = rm -f

all : ${NAME}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

.o : .c
	${CC} ${CFLAGS} -c $<

clean :
	${RM} ${OBJ}

fclean : 	clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
