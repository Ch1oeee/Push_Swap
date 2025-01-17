NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

GREEN = \033[38;5;114m
ROSE = \033[38;5;218m
BLUE = \033[38;5;153m
NC = \033[0m

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
		srcs/algo/mediane.c\
		srcs/algo/update_index.c\
		srcs/algo/calculate_cost.c\


OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBRARIES) $(OBJS)
	@echo "$(ROSE)\e[1m┌─────$(NAME)──────────────────────────────────┐\e"
	@echo "││$(BLUE)	      Compiling $(NAME) 🌀		$(ROSE) │"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBRARIES)
	@echo "$(RED)\e[1m┌─────$(NAME)──────────────────────────────────┐\e"
	@echo "││$(GREEN)	      \e[1mCompilation finished 🌱\e		$(ROSE) │"
	@echo "\e[1m└────────────────────────────────────────────────┘\e"

$(LIBRARIES):
	@$(MAKE) -C $(LIBRARIES_DIR) --no-print-directory

.c.o:
	@cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBRARIES_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBRARIES_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re