CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ps_opsp.c ps_opr.c main.c ft_dbllist.c\
		ft_dbllist2.c lst_create.c lst_check.c count_op.c\
		op_rotation.c final_order.c threeorder.c threeorderdec.c
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
