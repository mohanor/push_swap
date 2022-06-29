#include <stdio.h>
#include <stdlib.h>

struct stack {
    int value;
    struct stack* next;
} t_stack;

struct stack *push(struct stack *stack, int item)
{
    struct stack *pile;

    pile = (struct stack *)malloc(sizeof(struct stack));
    pile->value = item;
    pile->next = stack;
    return pile;
}

struct stack *push_cap(struct stack *stack, int cap)
{
    struct stack    *pile;
    int             i;
    int             tab[cap];
    int             j;

    j = 0;
    i = 1;
    while(i <= cap)
    {
        pile = (struct stack *)malloc(sizeof(struct stack));
        pile->value = rand() % cap;
        pile->next = stack;
        stack = pile;
        i++;
    }
    return pile;
}

struct stack *pop(struct stack *stack)
{
    struct stack *s;

    s = stack;
    stack = stack->next;
    free(s);
    return stack;
}

void    print_stack(struct stack *stack)
{
    if (!stack)
        printf("stack is empty");

    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

int     stacklen(struct stack *stack)
{
    struct stack *s;
    int           len;

    len = 0;
    s = stack;
    while(s)
    {
        len++;
        s = s->next;
    }

    return (len);
}

struct stack *empty_stack(struct stack *stack)
{
    struct stack *s;

    while(stack)
    {
        s = stack;
        stack = stack->next;
        free(s); 
    }
    
    return stack;
}

void    sort_tab(int *tab, int c)
{
    int i;
    int k;
    int tmp;

    k = 1;
    while (1)
    {
        k = 0;
        i = 0;
        while(i < c - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                k = 1;
            }
            i++;
        }
        if (k == 0)
        {
            break;
        }
    }
}

int main()
{
    struct stack *p;
    struct stack *i;
    struct stack *p2;
    int *tab;
    int *add;
    int c;
    int node_nbr;
    int div;

    c = 10;
    p2 = NULL;
    p = NULL;
    p = push_cap(p, c);

    tab = (int *)malloc(sizeof(int) * stacklen(p));
    if (!tab)
        return (0);

    add = tab;
    p2 = p;
    while(p2)
    {
        *add = p2->value;
        p2 = p2->next;
        add++;
    }

    sort_tab(tab, c);
    node_nbr = stacklen(p);
    // printf("%d\n", node_nbr);
    div = node_nbr / 5;

    int j;
    int s;

    while(stacklen(p2) < stacklen(p))
    {
        i = p;
        s = 0;
        while(i)
        {
            for(j = s; j < div + s; j++)
            {
                if (i->value == tab[j])
                {
                    p2 = push(p2, i->value);
                }
            }
            s += div;
            i = i->next;
        }
    }


    printf("\n");
    print_stack(p2);
    printf("\n");
    
        print_stack(p);

        int y;
        y = 0;
        printf("\n\n");
        while (y < c )
        {
            printf("%d\n", tab[y]);
            y++;
        }
    
    return (0);
}