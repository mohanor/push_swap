NAME = push_swap

NAME_B = checker

src = mondatory/main_sort.c mondatory/sort.c mondatory/utils.c\
		mondatory/split.c mondatory/sort_small.c push_swap.c\
		mondatory/sort2.c mondatory/sort3.c mondatory/utils2.c

src_b = bonus/bouns_sort1.c bonus/bouns_sort2.c bonus/bouns_sort3.c\
			bonus/bouns_utils4.c bonus/bouns_utils3.c bonus/bouns_utils2.c bonus/bouns_utils.c bonus/split.c bonus/get_next_line.c

obj = $(src:.c=.o)

obj_b = $(src_b:.c=.o)

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(obj) push_swap.h
	cc $(flags) $(src) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(src_b) $(obj_b) bonus/push_swap_bonus.h
	cc $(flags) $(src_b) -o $(NAME_B)

%.o: %.c
	cc -c $< -o $@

clean:
	rm -rf $(obj) $(obj_b)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all
	