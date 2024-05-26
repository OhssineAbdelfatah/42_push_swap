#include"push_swap.h"

int is_max(long nbr)
{
    if(nbr > 2147483647 ||  nbr < -2147483648)
        return 1;
    else 
        return 0;
}

int check_double(t_node *head)
{
    t_node *tmp;
    t_node *tmp1;

    tmp = head;
    while(tmp->next != NULL)
    {
        tmp1 = tmp->next ;
        while(tmp1 != NULL)
        {
            if(tmp1->data == tmp->data)
                return -1;
            tmp1 = tmp1->next ;
        }
        tmp = tmp->next ;
    }
    return 0;
}

int is_space(char c)
{
    if(c == ' ' || (c >= 13 && c <= 9))
        return 1;
    else
        return 0;
}

int is_sign(char c)
{
    if(c == '-' || c == '+')
        return 1;
    else 
        return 0;
}

char is_sign_doubled(char a, char b)
{
    if( (a == '-' && b == '-' ) || (a == '+' && b == '+' ))
        return 1;
    else
        return 0;
}


