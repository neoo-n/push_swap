CC = cc
FLAGS = -Wall -Wextra -Werror 
SRC = push_swap.c ps_ops.c main.c
#OBJDIR = obj
OBJ = ${SRC:.c=.o}
NAME = push_swap
RM = rm


all : ${NAME} 

${NAME} : ${OBJ} ${LIBFT}
	${AR} ${NAME} ${OBJ} ${LIBFT}

.o : .c
	${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#	mkdir -p ${OBJDIR}

${LIBFT} :
	${MAKE} -C ./libft/src

clean :
	${RM} -f ${OBJ}

fclean : 	clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
