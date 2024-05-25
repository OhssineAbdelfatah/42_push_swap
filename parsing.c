#include"push_swap.h"

// to be check
    // double number done
    // max-min int ...


// atoi

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
            nbr = ft_atol(arg[j]);
            if(is_max(nbr)){
                ft_putstr_fd("max checked : ERROR !\n",1);
                return NULL;
            }
            node = creat_node((int)nbr);
            add_to_stack(node, &head);
            free(arg[j]);
        }
        free(arg[j]);
        free(arg);
    }
    if(check_double(head) == -1){
        ft_putstr_fd("doubled check : ERROR!\n",1);
        return NULL;
    }
    // ft_putstr_fd("doubled check : OK!\n",1);
    // ft_putstr_fd("max checked : OK !\n",1);
    return head;
}

void free_stack(t_node *head)
{
    t_node *tmp;

    tmp = head->next;
    while(tmp != NULL)
    {
        free(head);
        head = tmp;
        tmp = tmp->next;
    }
    free(head);
    return ;
}

static int	space_sign(const char *s, int *sign)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == 32 || (s[i] < 14 && s[i] > 8)))
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			*sign *= (-1);
		i++;
	}
	return (i);
}
long	ft_atol(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;
	unsigned long long	temp;

	result = 0;
	sign = 1;
	i = space_sign(str, &sign);
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = result;
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}
//split

