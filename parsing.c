#include"push_swap.h"

// to be check
    // double number done
    // max-min int ...


// atoi


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

int check_args(int len, char **argv)
{
    int i;
    int j;
    int flag;

    i = 0 ;
    while(++i < len)
    {
        if( argv[i][0] == '\0' )
            return -1;
        j = -1 ;
        flag = 0;
        while(argv[i][++j])
        {
            if(is_sign_doubled(argv[i][j],argv[i][j+1]) || (ft_isdigit(argv[i][j]) && is_sign(argv[i][j+1]) ) )
                return -1;
            if(is_sign(argv[i][j]) && ( is_sign(argv[i][j+1]) || is_space(argv[i][j+1]) ))
                return -1;
            if( !ft_isdigit(argv[i][j]) && !is_space(argv[i][j]) && !is_sign(argv[i][j]))
                return -1;
            if(is_sign(argv[i][j]) && argv[i][j+1] == '\0')
                return -1;
            if(is_space(argv[i][j]))
                flag++;
        }
        if(flag == j )
            return -1;
    }
    return 0;
}

t_node *fill_args(char **argv )
{
    int i;
    int j;
    long nbr;
    char **arg;
    t_node *head;
    t_node *node;

    head =NULL;
    i = 0;
    while(argv[++i]){
        arg = ft_split(argv[i], ' ');
        j = -1;
        while(arg[++j])
        {
            nbr = ft_atoi(arg[j]);
            node = creat_node((int)nbr);
            add_to_stack(node, &head);
            free(arg[j]);
        }
        free(arg[j]);
        free(arg);
    }
    if(check_double(head) == -1){
       ft_putstr_fd("doubled check!\n",1);
        return NULL;
    }
    return head;
}

void free_stack(t_node *head)
{
    t_node *tmp;

    tmp = head->next;
    while(tmp->next != NULL)
    {
        free(head);
        head = tmp;
        tmp = tmp->next;
    }
    free(tmp);
    return ;
}

//split

