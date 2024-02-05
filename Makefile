NAME	= so_long
SRCS	= so_long.c utils.c map.c mov.c init.c file.c end.c 
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
MINILIBX	= minilibx/
OPENGL		= -framework OpenGL -framework AppKit
MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx
COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) $(MINILIBX)/libmlx.a

${NAME}:	${OBJS}
			@make -s -C $(MINILIBX) 2> /dev/null
			@$(CC) $(CFLAGS) $(SRCS) $(COMPILEPRM)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re