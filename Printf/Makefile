SRCS = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putptr_fd.c ft_putstr_fd.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc
RM = rm -f
AR = ar rc
RN = ranlib

C_FLAGS = -Wall -Wextra -Werror

.c.o : 
		${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : 	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}


all : $(NAME)

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re