NAME = push_swap

NAME_B = checker

src = mondatory/utils.c mondatory/split.c mondatory/lst.c push_swap.c

obj = $(src:.c=.o)


flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(obj) push_swap.h
	@gcc $(flags) $(src) -o $(NAME)

%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -rf $(obj) $(obj_b)

fclean: clean
	@rm -rf $(NAME) $(NAME_B)

re: fclean all
	