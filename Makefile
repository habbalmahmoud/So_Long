SRCS = main.c check_the_map.c validate.c so_long_utils.c handle_map_spots.c check_availability.c check_game_access.c window.c window_utils.c window_utils_more.c change_pos.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))

OBJS = ${SRCS_DIR:.c=.o}

NAME = so_long

LIBFT = Libft/libft.a

PRINT_F = Printf/libftprintf.a

GNL = GNL/gnl.a

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : $(NAME)

.c.o :
		${CC} ${C_FLAGS} -c $< -o ${<:.c=.o} $(INCLUDES)

$(NAME) : ${LIBFT} ${PRINT_F} ${GNL} $(MLX) ${OBJS}
		  ${CC} ${C_FLAGS} ${OBJS} ${LIBFT} ${PRINT_F} $(MLX_FLAGS) ${GNL} -o ${NAME}

$(LIBFT) :
		  @make -C ./Libft

$(PRINT_F) :
			@make -C ./Printf

$(MLX) :
		@make -C ./mlx

$(GNL) :
		@make -C ./GNL

clean :	
		@make clean -C ./Libft
		@make clean -C ./Printf
		@make clean -C ./GNL
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME} ${LIBFT} ${PRINT_F} ${GNL}

re : fclean all

.PHONY : all clean fclean re