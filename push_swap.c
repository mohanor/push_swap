#include "push_swap.h"

int has_alpha(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    if(str[i] == '\0')
        return (1);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

void my_exit(char *str)
{
    ft_putstr(str);
    exit(0);
}

void    print_tab(int *tab, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        /*if (i == len - 1)
        {
            printf("%d", tab[i]);
            return ;
        }*/
        printf("%d\n", tab[len]);
        len--;
    }
    //ft_putstr("\n");
}

int *tab_index(int *tab, int len)
{
    int *arr;
    int i;
    int j;
    int index;

    arr = (int *)malloc(sizeof(int) * len);
    if (!arr)
        return 0;
    i = 0;
    while (i < len)
    {
        j = 0;
        index = 0;
        while (j < len)
        {
            if (tab[i] > tab[j])
                index++;
            j++;
        }

        arr[i] = index;
        i++;
    }
    //free(tab);
    return arr;
}

void    random_3nbr(t_node *vars)
{
        if (vars->a[2] > vars->a[1])
       {
           if(vars->a[0] > vars->a[2])
               sa(vars->a, *vars->top_a, '1');
           if (vars->a[0] < vars->a[1])
           {
                sa(vars->a, *vars->top_a, '1');
                rra(vars->a, *vars->top_a);
           }
           if (vars->a[0] < vars->a[2] && vars->a[0] > vars->a[1])
                ra(vars->a, *vars->top_a, '1');
       }
       if (vars->a[2] < vars->a[1])
       {
           if(vars->a[1] > vars->a[0] && vars->a[0] > vars->a[2])
           {
                sa(vars->a, *vars->top_a, '1');
                ra(vars->a, *vars->top_a, '1');
           }
           if(vars->a[1] > vars->a[0] && vars->a[0] < vars->a[2])
                rra(vars->a, *vars->top_a);
       }
}

int find_min(int *a, int tb)
{
    int i;
    int min;
    int j;

    i = 0;
    min = a[0];
    j = 0;
    while (i <= tb)
    {
        if (min < a[i])
        {
            min = a[i];
            j = i;
        }
        i++;
    }

    return j;
}

int main(int ac, char **av)
{
    int i;
    char *ptr;
    char **tab;
    int *tmp;
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return 0;
    i = 1;
    if (ac < 2)
        my_exit("error1\n");

    while (av[i])
    {
        if(has_alpha(av[i]))
        {
            my_exit("error\n");
        }
        i++;
    }

    i = 1;
    ptr = NULL;
    while (av[i])
    {
        ptr = ft_strjoin(ptr, av[i]);
        ptr = ft_strjoin(ptr, " ");
        i++;
    }

    tab = ft_split(ptr, ' ');

    tmp = (int *)malloc((ac - 1) * sizeof(int));
    if (!tmp)
        return 0;

    i = 0;
    while (tab[i])
    {
        if(!not_long(tab[i]))
        {
            free(tab);
            free(tmp);
            my_exit("error\n");
        }

        tmp[i] = (int)ft_atoi(tab[i]);
        i++;
    }

    i = 0;
    int j;

    while (i < ac - 2)
    {
        j = i + 1;
        while(j < ac - 1)
        {
            if (tmp[i] == tmp[j])
                my_exit("error\n");
            j++;
        }
        i++;
    }
    
    node->a = tab_index(tmp, ac -1);
    int h = 0;
    int h2 = ac - 2;
    int kk;
    while (h <= h2)
    {
        kk = node->a[h];
        node->a[h] = node->a[h2];
        node->a[h2] = kk;
        h++;
        h2--;
    }
    node->b = (int *)malloc(sizeof(int) * ac - 1);
    if (!node->b)
        return 0;
    
    
    i = 0;
    while(i < ac - 1)
        node->b[i++] = -1;
    
    int la = ac - 2;
    int lb = -1;
    node->top_a = &la;
    node->top_b = &lb;
    // ft_putstr("p\n");
    //print_tab(node->a, *node->top_a);

    if (ac == 4)
    {
        random_3nbr(node);
        return 0;
    }

    int i_min;
    if (ac == 6)
    {
        i_min = find_min(node->a, *node->top_a);
        if (i_min >= 2)
        {
            while (i_min < *node->top_a)
            {
                ra(node->a, *node->top_a, '1');
                i_min++;
            }
        }else{
                rra(node->a, *node->top_a);
                rra(node->a, *node->top_a);
        }
        pb(node->a, node->b, node->top_a, node->top_b);
        i_min = find_min(node->a, *node->top_a);
        if (i_min == 2)
        {
            ra(node->a, *node->top_a, '1');
        }else{
            if (i_min == 1)
            {
                ra(node->a, *node->top_a, '1');
                ra(node->a, *node->top_a, '1');
            }
            if (i_min == 0)
            {
                rra(node->a, *node->top_a);
            }

        }
        pb(node->a, node->b, node->top_a, node->top_b);
        random_3nbr(node);

        if (node->b[1] > node->b[0])
            sb(node->b, *node->top_b + 1, '1');

        pa(node->a, node->b, node->top_a, node->top_b);
        if (node->a[*node->top_a - 1] < node->a[*node->top_a])
        {
            ra(node->a, *node->top_a, '1');
        }
        pa(node->a, node->b, node->top_a, node->top_b);
        if (node->a[*node->top_a - 1] < node->a[*node->top_a])
        {
            ra(node->a, *node->top_a, '1');
        }
//print_tab(node->a, *node->top_a);
        return 0;
    }
    push_sorted_to_b(node);
    //print_tab(node->b, *node->top_b);
    //ft_putstr("\n");
    push_sorted_to_a(node);
    // print_tab(node->a, *node->top_a);

/*
    int y = *node->top_a;
     while (0 <= y)
     {
        printf("%d\n", tmp[node->a[y]]);
        y--;
     }*/
    //print_tab(node->a, *node->top_a);
    return (0);
}