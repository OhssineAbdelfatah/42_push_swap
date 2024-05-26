#include "push_swap.h"

t_node *creat_node(int num)
{
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    if(!node)
        throw_error("node allocation failed.");
    node->data = num;
    node->side = false;
    node->next = NULL;
    node->move = 0;
    node->ind = 0;
    return node;
}

void set_stack_to_zero(t_node **stack)
{
    t_node *tmp;

    if(*stack == NULL)
        return ;
    tmp = *stack;
    while(tmp != NULL){
        tmp->ind = 0;
        tmp->move = 0;
        tmp->side = false;
        tmp = tmp->next ;
    }
    return ;
}

void add_to_stack(t_node *node, t_node **head)
{
    t_node *tmp;

    if(*head == NULL){
        *head = node;
        return ;
    }
    tmp = *head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = node;
    return ;
}

void print(t_node *stack_a, t_node *stack_b)
{
   ft_printf("\n");
    t_node *tmp = stack_a;
    t_node *tmp1 = stack_b;
    ft_printf("stack a :\n head \t");
    while(tmp != NULL){
        ft_printf("%d \t",tmp->data);
        tmp = tmp->next;
    }
    ft_printf("\n----------------------\n");
    /*stack a*/

    /*stack b*/
    ft_printf("stack b :\n head \t");
    while(tmp1 != NULL){
        ft_printf("%d \t",tmp1->data);
        tmp1 = tmp1->next;
    }
    ft_printf("\n----------------------\n");
}

void push_swap(char **args)
{
    t_node *stack_a ;
    t_node *stack_b ;

    stack_b = NULL;
    stack_a = fill_args(args);
    if(stack_a == NULL)
        return ;
    push_min_to_b(&stack_a, &stack_b); // add inside push in best move
    sort_3_nbr(&stack_a);

    free_stack(stack_a);

    return ;
}

int main(int argc, char **argv){
    if(argc >= 2){
        if(check_args(argc, argv) == -1){
            ft_putstr_fd("check args : ERROR.\n",2);
            return 0;
        }
        // else
        //     ft_putstr_fd("check args : OK.\n",1);
        push_swap(argv);
    }else
        ft_printf("error too few args.\n");
    // system("leaks push_swap");
        
}

