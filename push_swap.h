#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include"ft_printf/ft_printf.h"
#include"libft/libft.h"


typedef struct s_node {
    int data;
    struct s_node *next;
} t_node ; 

//utils

char	*ft_itoa(int n);
// static size_t	count_size(int nbr);
void throw_error(char *str);


// push swap
t_node *creat_node(int num);
void add_to_stack(t_node *node, t_node **head);

// rules 
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void ss(t_node *stack_a, t_node *stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_b, t_node **stack_a);
void ra(t_node **stack_a);
void rb(t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

// parsing

char is_sign_doubled(char a, char b);
int is_space(char c);
int check_args(int len, char **argv);
int is_sign(char c);
t_node *fill_args(char **argv);
int check_double(t_node *head);
void free_stack(t_node *head);


#endif