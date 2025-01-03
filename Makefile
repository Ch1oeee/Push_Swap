NAME = push_swap
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBRARIES_DIR = ./Libraries
LIBRARIES = $(LIBRARIES_DIR)/libft.a

SRCS =	srcs/push_swap.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBRARIES) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBRARIES):
	make -C $(LIBRARIES_DIR)

.c.o:
	cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBRARIES_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBRARIES_DIR) fclean

re: fclean all

.PHONY: all clean fclean re