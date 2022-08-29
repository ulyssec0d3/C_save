SRCS = ft_error.c ft_sort_tab.c main.c parse_dict.c read_file.c casual.c ft_split.c print_words.c transalte_number.c

OBJS = ${SRCS:.c=.o}

NAME = rush-02

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${OBJS}
	gcc -Wall -Wextra -Werror -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

.PHONY: all clean fclean
