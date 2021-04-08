ERASE   = \033[2K\r
GREY    = \033[30m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
PINK    = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m
END     = \033[0m
BOLD    = \033[1m
UNDER   = \033[4m
SUR     = \033[7m

NAME		= checker

SRCS		=	srcs/checker/checker.c \
				srcs/checker/check_params.c \
				srcs/utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3

INCLUDE		= -Iinclude -I${LIBFT}/include

RM			= rm -f

LIBFT		= libft

all:		libft ${NAME}

libft: 
			make -C ${LIBFT}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -L ${LIBFT} -lft -o ${NAME}
			echo "$(BOLD)${GREEN}--> checker generated <--${END}"

%.o:		%.c include/push_swap.h
			${CC} ${CFLAGS} $(INCLUDE) -c  $< -o $@

clean:
			${RM} ${OBJS}
			make clean -C $(LIBFT)

fclean:		clean
			${RM} ${NAME}
			make fclean -C $(LIBFT)
			echo "${RED}XXXXX CLEAN XXXXX${END}"

re			: fclean all

.PHONY: 	clean fclean all re compil libft
.SILENT:	clean fclean all re compil ${OBJS} ${NAME} libft