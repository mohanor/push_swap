#include "../push_swap.h"

void    sa(int *tab, int len)
{
    int tmp;

    tmp = tab[len - 1];
    tab[len - 1] = tab[len - 2];
    tab[len - 2] = tmp; 
}

void    sb(int *b, int len)
{
    int tmp;

    tmp = b[len - 1];
    b[len - 1] = b[len - 2];
    b[len - 2] = tmp; 
}

void    ss(int *a, int *b, int top_a, int top_b)
{
    sa(a, top_a + 1);
    sb(b, top_b + 1);
}

void pa(int *a, int *b, int *top_a, int *top_b)
{
    a[*top_a + 1] = b[*top_b];
    *top_b -= 1;
    *top_a += 1;
}

void pb(int *a, int *b, int *top_a, int *top_b)
{
    b[*top_b + 1] = a[*top_a];
    *top_b += 1;
    *top_a -= 1;
}

void    ra(int *a, int top_a)
{
    int i;
    int p;

    p = a[top_a];
    i = 0;
    while (0 < top_a)
    {
        a[top_a] = a[top_a - 1]; 
        top_a--;
    }
    a[0] = p;
}

void    rb(int *b, int top_b)
{
    int i;
    int p;

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
    ra(a, top_a);
    rb(b, top_b);
}

void    rra(int *a, int top_a)
{
    int i;
    int p;

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
    rra(a, top_a);
    rrb(b, top_b);
}

// 2 3 4 5 6 1