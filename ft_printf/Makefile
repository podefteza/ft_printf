NAME = libftprintf.a

SRCS =	ft_printf.c \
	ft_printfc.c \
	ft_printfs.c \
	ft_printfp.c \
	ft_printfnumber.c \
	ft_printfu.c \
	ft_printfx.c \

OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

