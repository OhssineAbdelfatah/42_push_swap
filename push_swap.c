#include "push_swap.h"

t_node *creat_node(int num){
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    if(!node)
        throw_error("node allocation failed.");
    node->data = num;
    node->next = NULL;
    return node;
}

void add_to_stack(t_node *node, t_node **head){
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

void push_swap(char **args, int argc){
    // int i;
    t_node *stack_a ;
    t_node *stack_b ;
    t_node *tmp ;
    (void)argc;
    stack_a = fill_args(args);
    if(stack_a == NULL)
        return ;
    stack_b = NULL;


    tmp = stack_a;
    ft_printf("stack a original:\n");
    while(tmp != NULL){
        ft_printf("stack_a %d\n",tmp->data);
        tmp = tmp->next;
    }
    free_stack(stack_a);
    while (1);
    return ;

    // print satck a
    tmp = stack_a;
        ft_printf("stack_a \n");
    while(tmp != NULL){
        ft_printf(" %d ",tmp->data);
        tmp = tmp->next;
    }

    // print satck b
    tmp = stack_b;
        ft_printf("\nstack_b\n");
    while(tmp != NULL){
        ft_printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    ft_printf("\n");

}

int main(int argc, char **argv){
    if(argc >= 2){
        // int i = 0;
        // char **args = ft_split(argv[1], ' ');
        // while(args[i] != NULL){
            // ft_putstr_fd(args[i++] ,1 );
            // ft_putstr_fd("\n" ,1 );
        // }
        
        if(check_args(argc, argv) == -1){
            ft_putstr_fd("error.\n",2);
            return 0;
        }
        else
            ft_putstr_fd("OK.\n",1);
        push_swap(argv,argc);
    }else
        ft_printf("error too few args.\n");
        
}