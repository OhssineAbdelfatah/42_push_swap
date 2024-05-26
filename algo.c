#include "push_swap.h"

// useful   
/* t_node *count_move_a(t_node *stack_a)
{
    int pos ;
    t_node *tmp;

    // Find the indexe of big_a in stack A.
    pos = 0;
    tmp = stack_a;
    while(tmp != NULL)
    {
        // tmp->ind_a = pos ;
        if(pos > lstsize(stack_a)/2){
            // tmp->side_a = true;
            tmp->move += (lstsize(stack_a) - pos);
        }
        else
            tmp->move +=  pos ;
        tmp = tmp->next;
        pos++;
    }
    return stack_a ;
} */

t_node *count_move_b(t_node __unused *stack_b, t_node __unused **stack_a)
{
   /*  t_node *tmp_b;
    t_node *tmp_a;
    int indice ;
    int i ;
    int value;
    // // int to_push = INT32_MAX;

    if(stack_b == NULL)
        return ;

    // Find the indexe of the nearest number to big_a in stack B.
    tmp_a = stack_a;
    while(tmp_a != NULL)
    {
        // should loop over stack a , count each one moves
        i = 0;
        indice = 0 ;
        value = INT32_MIN;
        tmp_b = stack_b ;
        while(tmp_b != NULL)
        {
            if(tmp_b->data < tmp_a->data && tmp_b->data > value)
            {
                value = tmp_b->data ;
                indice = i;
            }
            tmp_b = tmp_b->next;
            i++;
        }
        if(value == INT32_MIN)
            indice = find_max_indice(stack_b);
        tmp_a->ind_b = indice ;
        if(indice > lstsize (stack_b)/2)
        {
            tmp_a->side_b = true;
            tmp_a->move =  lstsize(stack_b) - indice ;
        }
        else
            tmp_a->move = indice;  
        // ft_printf("move_a{%d} ind_a{%d} \n", tmp_a->move, tmp_a->ind_a, tmp_a->ind_b, tmp_a->side );
        tmp_a = tmp_a->next;
    }

    return stack_a; */
    return NULL;
}

int find_max_indice(t_node *stack_b)
{
    int max;
    int indice;
    int i = 0 ;
    t_node *tmp;

    if(stack_b == NULL)
        return 0;
    max = stack_b->data ;
    tmp = stack_b;
    while(tmp != NULL)
    {
        if(tmp->data > max)
        {
            max = tmp->data;
            indice = i;
        }
        i++;
        tmp = tmp->next;
    }
    return indice;
} 

int find_min(t_node *stack_b)
{
    int min;
    int indice;
    int i = 0 ;
    t_node *tmp;

    if(stack_b == NULL)
        return 0;
    min = stack_b->data ;
    tmp = stack_b;
    while(tmp != NULL)
    {
        if(tmp->data < min)
        {
            min = tmp->data;
            indice = i;
        }
        i++;
        tmp = tmp->next;
    }
    return indice;
} 


int count_move(t_node *stack_b, int ref)
{
    int ind;
    int i;
    int min;
    t_node *tmp;

    min = INT32_MIN;
    i = 0 ;
    tmp = stack_b;
    while(tmp != NULL)
    {
        if( tmp->data > min && tmp->data < ref)
        {
            min = tmp->data;
            ind = i;
        }
        i++;
        tmp = tmp->next;
    }
    if(min == INT32_MIN)
        return -1;
    return ind;
}

int count_move_a(t_node *stack_a, int ref)
{
    int ind;
    int i;
    int max;
    t_node *tmp;

    max = INT32_MAX;
    i = 0 ;
    tmp = stack_a;
    while(tmp != NULL)
    {
        if( tmp->data < max && tmp->data > ref)
        {
            max = tmp->data;
            ind = i;
        }
        i++;
        tmp = tmp->next;
    }
    if(max == INT32_MAX)
        return -1;
    return ind;
}