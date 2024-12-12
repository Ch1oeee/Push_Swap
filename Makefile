NAME = push_swap.a
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS =	push_swap.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus