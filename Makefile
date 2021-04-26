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

NAME_CHECK		= checker
NAME_PUSH		= push_swap
SRCS_PUSH		=	srcs/pushswap_fold/main.c \
					srcs/pushswap_fold/generate_list_inst.c \
					srcs/pushswap_fold/sort_a.c \
					srcs/pushswap_fold/sort_b.c \
					srcs/pushswap_fold/utils.c \
					srcs/pushswap_fold/sort_pack_of_3.c
SRCS_CHECK		= 	srcs/checker_fold/main.c \
					srcs/checker_fold/manage_instructions.c \
					srcs/checker_fold/check_if_ok.c
SRCS_SHARED		=	srcs/instructions/s.c \
					srcs/instructions/p.c \
					srcs/instructions/r.c \
					srcs/instructions/rr.c \
					srcs/utils/check_params.c \
					srcs/utils/fail.c \
					srcs/utils/print_stack.c \
					srcs/utils/print_repartition.c \
					srcs/utils/print_instructions.c \
					srcs/utils/ft_atoi_pushswap.c \
					srcs/utils/ft_strdup_pushswap.c \
					srcs/utils/ft_putnbr_fd_pushswap.c

OBJS_SHARED		= ${SRCS_SHARED:srcs/%.c=$(OBJS_DIR)/%.o} 
OBJS_PUSH		= ${SRCS_PUSH:srcs/%.c=$(OBJS_DIR)/%.o} ${OBJS_SHARED}
OBJS_CHECK		= ${SRCS_CHECK:srcs/%.c=$(OBJS_DIR)/%.o} ${OBJS_SHARED}
OBJS_DIR		= objs
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra # -fsanitize=address -g3
INCLUDE			= -Iinclude -I${LIBFT}/include
RM				= rm -rf
MKDIR			= mkdir -p
LIBFT			= libft

all:			libft ${NAME_PUSH} $(NAME_CHECK)

$(OBJS_DIR):
				$(MKDIR) $@

libft: 
				make -C ${LIBFT}

${NAME_PUSH}:	${OBJS_DIR} ${OBJS_PUSH}
				${CC} ${CFLAGS} ${INCLUDE} ${OBJS_PUSH} -L ${LIBFT} -lft -o ${NAME_PUSH}
				echo "$(BOLD)${GREEN}--> push_swap generated <--${END}"

${NAME_CHECK}:	${OBJS_DIR} ${OBJS_CHECK}
				${CC} ${CFLAGS} ${INCLUDE} ${OBJS_CHECK} -L ${LIBFT} -lft -o ${NAME_CHECK}
				echo "$(BOLD)${GREEN}--> checker generated <--${END}"

$(OBJS_DIR)/%.o:srcs/%.c include/push_swap.h
				$(MKDIR) $(dir $@)
				${CC} ${CFLAGS} $(INCLUDE) -c  $< -o $@

clean:
				${RM} ${OBJS_PUSH} ${OBJS_CHECK}
				make clean -C $(LIBFT)

fclean:			clean
				${RM} $(OBJS_DIR) $(NAME_PUSH) ${NAME_CHECK}
				make fclean -C $(LIBFT)
				echo "${RED}XXXXX CLEAN XXXXX${END}"

re:				fclean all

.PHONY: 		clean fclean all re compil libft
.SILENT:		clean fclean all re compil libft ${OBJS_PUSH} ${OBJS_CHECK} $(NAME_PUSH) ${NAME_CHECK} $(OBJS_DIR)