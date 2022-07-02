#include "../push_swap.h"

void    sa(int *tab, int len, char c)
{
    int tmp;

    if (c == '1')
        ft_putstr("sa\n");
    tmp = tab[len - 1];
    tab[len - 1] = tab[len - 2];
    tab[len - 2] = tmp; 
}

void    sb(int *b, int len, char c)
{
    int tmp;

    if (c == '1')
        ft_putstr("sb\n");
    tmp = b[len - 1];
    b[len - 1] = b[len - 2];
    b[len - 2] = tmp; 
}

void    ss(int *a, int *b, int top_a, int top_b)
{
    ft_putstr("ss\n");
    sa(a, top_a + 1 , '2');
    sb(b, top_b + 1, '2');
}

void pa(int *a, int *b, int *top_a, int *top_b)
{
    ft_putstr("pa\n");
    a[*top_a + 1] = b[*top_b];
    *top_b -= 1;
    *top_a += 1;
}

void pb(int *a, int *b, int *top_a, int *top_b)
{
    ft_putstr("pb\n");
    if (*top_a > -1)
    {
        b[*top_b + 1] = a[*top_a];
        *top_b += 1;
        *top_a -= 1;
    }
}

void    ra(int *a, int top_a, char c)
{
    int i;
    int p;

    if (c == '1')
        ft_putstr("ra\n");
    p = a[top_a];
    i = 0;
    while (0 < top_a)
    {
        a[top_a] = a[top_a - 1]; 
        top_a--;
    }
    a[0] = p;
}

void    rb(int *b, int top_b, char c)
{
    int i;
    int p;

    if (c == '1')
        ft_putstr("rb\n");
    p = b[top_b];
    i = 0;
    
    while (0 < top_b)
    {
        b[top_b] = b[top_b - 1]; 
        top_b--;
    }
    b[0] = p;
}

void    rr(int *a, int *b, int top_a, int top_b)
{
    ft_putstr("rr\n");
    ra(a, top_a, '2');
    rb(b, top_b, '2');
}

void    rra(int *a, int top_a)
{
    int i;
    int p;

    ft_putstr("rra\n");
    p = a[0];
    i = 0;
    while (i <= top_a - 1)
    {
        a[i] = a[i + 1]; 
        i++;
    }
    a[top_a] = p;
}

void    rrb(int *b, int top_b)
{
    int i;
    int p;

    ft_putstr("rrb\n");
    p = b[0];
    i = 0;
    while (i <= top_b - 1)
    {
        b[i] = b[i + 1]; 
        i++;
    }
    b[top_b] = p;
}

void    rrr(int *a, int *b, int top_a, int top_b)
{
    ft_putstr("rrr\n");
    rra(a, top_a);
    rrb(b, top_b);
}

// 2 3 4 5 6 1