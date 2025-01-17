NAME = libft.a
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS =	ft_isdigit.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_calloc.c\
		ft_substr.c\
		ft_bzero.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strcmp.c\
		ft_lstadd_back.c\
		ft_lstnew.c\
		ft_lstlast.c\
		ft_lstsize.c\
		ft_lstadd_front.c\
		ft_lstclear.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

.c.o:
	@cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re