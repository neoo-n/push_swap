CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ps_ops.c main.c ft_dbllist.c ft_putlst.c lst_checkcreate.c
#OBJDIR = obj
OBJ = ${SRC:.c=.o}
NAME = push_swap
LIBFT = libft/libft.a
RM = rm


all : ${NAME} 

${NAME} : ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}

.o : .c
	@${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#	mkdir -p ${OBJDIR}

${LIBFT} :
	@${MAKE} -C ./libft/

clean :
	@${RM} -f ${OBJ}
	@${MAKE} -C ./libft clean

fclean : 	clean
	@${RM} -f ${NAME}
	@${MAKE} -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re
