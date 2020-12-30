NAME = libftprintf.a

SRC  = src/ft_printf.c src/parser/pf_parser_main.c src/parser/pf_parser_parse_flags.c src/parser/pf_parser_parse_width.c src/parser/pf_parser_parse_precision.c src/parser/pf_parser_parse_size.c
OBJ  = ${SRC:c=o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -I include -L lib -c $^ -o $@

all: $(NAME)

$(NAME): ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -f src/*/*.o
	rm -f src/*.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all, ${NAME}, clean, fclean, re