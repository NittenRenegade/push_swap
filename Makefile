# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:37:41 by coskelet          #+#    #+#              #
#    Updated: 2022/03/05 12:06:36 by coskelet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

HEADER	= push_swap.h

SRCS	= sorter.c push_swap_engine.c \
		stack_constructor.c stack_utils.c stack_comparator.c \
		move_swap.c move_push.c move_rotate.c move_rrotate.c 

SRC_CHK	= checker.c stack_constructor.c stack_utils.c \
		move_swap.c move_push.c move_rotate.c move_rrotate.c

LIBFT	= libft

CHECKER	= checker

.PHONY:	all clean fclean re bonus

OBJS	= ${SRCS:.c=.o}
OBJCHK	= ${SRC_CHK:.c=.o}

%o : %c		${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

CC		= cc
RM		= rm -rf
AR		= ar -rcs
CFLAGS	= -Wall -Wextra -Werror
SANIT	= -g -fsanitize=address

$(NAME):	${OBJS} ${LIBFT}.a
			${CC} ${CFLAGS} ${SANIT} ${OBJS} -L ./${LIBFT} -lft -o $@

$(CHECKER):	${OBJCHK} ${LIBFT}.a
			${CC} ${CFLAGS} ${SANIT} ${OBJCHK} -L ./${LIBFT} -lft -o $@

$(LIBFT).a:
			@make -C ${LIBFT}
			@cp ${LIBFT}/${LIBFT}.a ./${LIBFT}.a
			
%o : %c		${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

bonus:		${CHECKER}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${OBJCHK}
			@make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${CHECKER}
			${RM} ${LIBFT}.a
			@make fclean -C ${LIBFT}

re:			fclean
			${NAME}
