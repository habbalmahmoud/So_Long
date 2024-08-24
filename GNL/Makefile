SRCS = get_next_line_utils.c get_next_line.c

OBJS = ${SRCS:.c=.o}

NAME = gnl.a

CC = cc
RM = rm -f
AR = ar rc
RN = ranlib

C_FLAGS = -Wall -Wextra -Werror

.c.o :
		${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all : $(NAME)

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re