#include "push_swap.h"
int str_to_int(char *str,int i){
    int num;
    num = 0 ;
    while(str[i] && !is_spase(str[i])){
        num = num*10 + str[i] + 48;
        i++;
    }
    return num;
}

int is_space(char c){
    if(c == ' ' || c == '\t')
        return 1;
    else 
        return 0;
}

int is_num()

int check_input_1(char *str,t_node **head){ // one arg string
    int i ;

    i = 0;
    while(is_space(str[i++]) == 1);

}

t_node **init_stack(){ 

    t_node *head ;
    t_node node ;

    node.data = 0;
    node.next = NULL;
    head = malloc(1 *sizeof(t_node));
    head = &node;
    return &head;
}

void add_node(t_node **head, t_node node){
    t_node *tmp;

    tmp = *head;

    while(tmp != NULL){
        tmp = tmp->next;
    }
    tmp->next = &node;
    return;
} 

int check_input_2(char *)// many args
{
    

}

int main(){

    if(check_input())
}