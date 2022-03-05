NAME	= libft.a

HEADER	= libft.h

SRCS	=	ft_strlen.c		ft_isalpha.c	ft_toupper.c	ft_memchr.c \
			ft_strchr.c		ft_isdigit.c 	ft_tolower.c	ft_memset.c \
			ft_strrchr.c	ft_isalnum.c	ft_atoi.c		ft_memcpy.c \
			ft_strncmp.c	ft_isascii.c	ft_calloc.c 	ft_memmove.c \
			ft_strnstr.c	ft_isprint.c	ft_bzero.c		ft_memcmp.c \
			ft_strdup.c		ft_isnum.c	 	ft_split.c 		ft_putchar_fd.c \
			ft_substr.c		ft_isint.c		ft_itoa.c 		ft_putstr_fd.c \
			ft_strjoin.c				 					ft_putendl_fd.c \
			ft_striteri.c	ft_strmapi.c	ft_putnbr_fd.c \
			ft_strtrim.c 	\
			ft_strcmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c \
			ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c \
			ft_lstclear.c		ft_lstiter.c			ft_lstiter_reverse.c \
			ft_lst_issort.c		ft_lst_isdup.c 			ft_lstshortclear.c \
			ft_lstsublast.c 	ft_lst_getfpos.c		ft_lstmap.c \
			get_next_line.c		get_next_line_utils.c \
			ft_sort_quick.c \
			ft_print_intarr.c	ft_print_nbr.c	ft_printstr.c

.PHONY:	all clean fclean re bonus

OBJS	= ${SRCS:.c=.o}

CC		= cc

RM		= rm -f

AR		= ar -rcs

CFLAGS	= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} $?

%o : %c ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

