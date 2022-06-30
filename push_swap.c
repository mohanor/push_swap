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
    while (i < len)
    {
        /*if (i == len - 1)
        {
            printf("%d", tab[i]);
            return ;
        }*/
        printf("%d\n", tab[len - 1]);
        len--;
    }
    ft_putstr("\n");
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
    free(tab);
    return arr;
}
int main(int ac, char **av)
{
    int i;
    char *ptr;
    char **tab;
    int *tmp;
    int *a;
    int *b;

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

    // int top_p = 0;
    a = tab_index(tmp, ac -1);
    b = (int *)malloc(sizeof(int) * ac - 1);
    if (!b) return 0;
    i = 0;
    while(i < ac - 1)
        b[i++] = -1;
    if (!b)
        my_exit("error\n");
    // print_tab(b, ac - 1);

    int ta = ac - 2;
    int tb = -1;
    pb(a, b, &ta, &tb);
    printf("\n");
   

    pb(a, b, &ta, &tb);
    printf("\n");
    

    pb(a, b, &ta, &tb);
    printf("\n");

    print_tab(a, ta + 1);
    printf("\n");
    print_tab(b, tb + 1);
    return (0);
}