# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 15:50:49 by tde-souz          #+#    #+#              #
#    Updated: 2023/06/26 19:06:02 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************************************************************
# *									SETTINGS								   *
# ******************************************************************************
NAME		:=	so_long

CURRENT_OS	:=	$(shell uname)
INCLUDES	= -I headers/ -I libft/
LIBFT_DIR	:=	libft/
LIBFT		:=	libft
MLX			:=	libmlx

# ******************************************************************************
# *								   TEXT COLORS								   *
# ******************************************************************************
GREEN		:=	\e[38;5;118m
GOLD		:=	\e[38;5;220m
RESET		:=	\e[0m
BOLD		:=	\e[1m

# ******************************************************************************
# *								 COMPILATION FLAGS							   *
# ******************************************************************************
CFLAGS		= -g -Wall -Werror -Wextra ${INCLUDES}
LDFLAGS		= -L ${MLX_DIR} -l mlx -L libft/ -l ft -lXext -lX11 -lm -lz -O3
ifeq ($(CURRENT_OS), Linux)
CFLAGS		+=	-fPIE
TITLE		:=	"Silent Viras [ Linux edition ]"
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -lXext -lX11 -lm -lz -O3
INCLUDES	+=	-I minilibx/minilibx_linux/
MLX_DIR		=	minilibx/minilibx_linux/
else
TITLE		:=	"Silent Viras [ Mac edition ]"
LDFLAGS		=	-L ${MLX_DIR} -l mlx -L libft/ -l ft -framework OpenGL -framework AppKit
INCLUDES	+=	-I minilibx/minilibx_mac/
MLX_DIR		=	minilibx/minilibx_mac/
endif

# ******************************************************************************
# *								   SOURCE FILES								   *
# ******************************************************************************
DIR_SRCS	:= srcs/

SRCS		:=	error/error_manager.c								\
				game/game_manager.c game/render_game.c				\
				input/input.c input/move.c							\
				map/map.c											\
				so_long.c											\
				window/window_manager.c								\
				parse/parse_arguments.c parse/parse_map.c			\
				parse/parse_map_utils.c								\
				solver/recursive_maze_solver.c

OBJS		:= $(addprefix $(DIR_SRCS), $(SRCS:.c=.o))

# ******************************************************************************
#                                     RULES                                    *
# ******************************************************************************
all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT}.a ${MLX_DIR}${MLX}.a ${OBJS}
ifeq (${CURRENT_OS}, Linux)
		${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
else
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}
endif

${LIBFT_DIR}${LIBFT}.a:
	make -C ${LIBFT_DIR} extra

${MLX_DIR}${MLX}.a:
	make -C ${MLX_DIR}

clean:
	${RM} ${OBJS}

fclean:		clean
	make -C ${LIBFT_DIR} fclean
	make -C ${MLX_DIR} clean
	${RM} -r ${NAME}.dSYM
	${RM} ${NAME}

re:			fclean all


MAP :=
leak:
	@make && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${MAP}

.PHONY: all clean fclean re leak
