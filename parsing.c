#include"push_swap.h"

// to be check
    // double number
    // max-min int


// atoi
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
        if( argv[i][0] == '\0' || flag == j )
            return -1;
        j = -1 ;
        flag = 0;
        while(argv[i][++j])
        {
            if(is_sign_doubled(argv[i][j],argv[i][j+1]))
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
    }
    return 0;
}

t_node *fill_args(char **argv, int argc){
    int i;
    (void)argc;
    int j;
    long nbr;
    char **arg;
    t_node *head;
    t_node *node;

    head =NULL;
    i = 0;
    while(argv[++i]){
        ft_putstr_fd("argv i \n" ,1);
        ft_putstr_fd(argv[i] ,1);
        ft_putstr_fd("\n" ,1);
        arg = ft_split(argv[i], ' ');
        ft_putstr_fd("\n" ,1);
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
    return head;
}

//split

