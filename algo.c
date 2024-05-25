#include "push_swap.h"

// useful   
t_node *count_move_a(t_node *stack_a)
{
    int pos ;
    t_node *tmp;

    // Find the indexe of big_a in stack A.
    pos = 0;
    tmp = stack_a;
    while(tmp != NULL)
    {
        tmp->ind_a = pos ;
        if(pos > lstsize(stack_a)/2){
            tmp->side_a = true;
            tmp->move += (lstsize(stack_a) - pos);
        }
        else
            tmp->move +=  pos ;
        tmp = tmp->next;
        pos++;
    }
    return stack_a ;
}

t_node *count_move_b(t_node *stack_b, t_node *stack_a)
{
    t_node *tmp_b;
    t_node *tmp_a;
    int indice ;
    int i ;
    int value;
    // // int to_push = INT32_MAX;

    if(stack_b == NULL)
        return 0;

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
            tmp_a->move += lstsize(stack_b) - indice ;
        }
        else
            tmp_a->move += indice;  
        tmp_a = tmp_a->next;
    }
    return stack_a;
}




int find_max_indice(t_node *stack_b)
{
    int max;
    int indice;
    int i = 0 ;

    max = stack_b->data ;
    while(stack_b != NULL)
    {
        if(stack_b->data > max)
        {
            max = stack_b->data;
            indice = i;
        }
        stack_b = stack_b->next;
        i++;
    }
    return indice;
} 