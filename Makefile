NAME		= libftprintf.a

DIR_INC		= ./includes

HEADER		= $(DIR_INC)/ft_printf.h

CC		= cc

ifeq		($(DEBUG), 1)
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
else
CFLAGS		= -Wall -Wextra -Werror
endif

AR		= ar rcs

RM		= rm -f

DIR_LIB		= ./lib
LIB		= $(addprefix $(DIR_LIB)/, \
			ft_calloc.c	\
			ft_memset.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_strchr.c	\
			ft_strdup.c	\
			ft_strlen.c	\
			)
LIB_OBJS	= $(LIB:.c=.o)

DIR_SRC		= ./sources
SRC		= $(addprefix $(DIR_SRC)/, \
			ft_printf.c	\
			aux_functions.c	\
			)
SRC_OBJS	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(LIB_OBJS) $(SRC_OBJS)
			$(AR) $(NAME) $(LIB_OBJS) $(SRC_OBJS)

%.o: 		%.c $(HEADER) Makefile
			$(CC) $(CFLAGS) -o $@ -c $< -I $(DIR_INC)

clean:
			$(RM) $(LIB_OBJS) $(SRC_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
