#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stack {
    int value;
    struct stack * next;
} t_stack;

int	    ft_strlen(char *p);
void	ft_putstr(char *s);
void	ft_putchar(char c);
t_stack    *new_item(int item);
void    add_back(t_stack **list, t_stack *new);
long long	ft_atoi(char *str);
int	ft_nbrlen(long long nb);

#endif