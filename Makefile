NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

LIBRARIES_DIR = ./Libraries
LIBRARIES = $(LIBRARIES_DIR)/libft.a

SRCS =	srcs/push_swap.c\
		srcs/parsing/parsing.c\
		srcs/parsing/init_list.c\
		srcs/instructions/instructions_swap.c\
		srcs/instructions/instructions_rotate.c\
		srcs/instructions/instructions_rev_rotate.c\
		srcs/instructions/instructions_push.c\
		srcs/algo/small_algo.c\
		srcs/algo/gen_algo.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBRARIES)
	cc $(FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

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