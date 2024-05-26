#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdbool.h>
#include"ft_printf/ft_printf.h"
#include"libft/libft.h"


/*//////////////////////////////////////////////////////////////////////
//                             STRUCTS                                //
/3/////////////////////////////////////////////////////////////////////*/

typedef struct s_res {
    int value;
    int error;
} t_res;

typedef struct s_push{
    int target;
    int base;
} t_push;

typedef struct s_node {
    int data;
    int ind;
    int move;
    bool side;
    struct s_node *next;
} t_node ; 

/*//////////////////////////////////////////////////////////////////////
//                             RULES                                  //
//////////////////////////////////////////////////////////////////////*/

void sa_sb(t_node **stack, char status);
void pa_pb(t_node **base, t_node **target,char status);
void ra_rb(t_node **stack, char status);
void rra_rrb(t_node **stack, char status);

void ss(t_node *stack_a, t_node *stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

/*//////////////////////////////////////////////////////////////////////
//                             PARSING                                //
//////////////////////////////////////////////////////////////////////*/

char is_sign_doubled(char a, char b);
int is_space(char c);
int check_args(int len, char **argv);
int is_sign(char c);
t_node *fill_args(char **argv);
int check_double(t_node *head);
void free_stack(t_node *head);
long	ft_atol(const char *str);
int is_max(long nbr);

/*//////////////////////////////////////////////////////////////////////
//                             UTILS                                  //
//////////////////////////////////////////////////////////////////////*/

char	*ft_itoa(int n);
void throw_error(char *str);
int	lstsize(t_node *lst);

/*//////////////////////////////////////////////////////////////////////
//                             PUSH SWAP                              //
//////////////////////////////////////////////////////////////////////*/

void set_stack_to_zero(t_node **stack);
t_node *creat_node(int num);
void add_to_stack(t_node *node, t_node **head);
void print(t_node *stack_a, t_node *stack_b);

// sort
void sort_3_nbr(t_node **head);
void sort_5_nbr(t_node **stack_a, t_node **stack_b);

// algo 
int find_min(t_node *stack_b);
// t_node *count_move_a(t_node *stack_a);
int find_max_indice(t_node *stack_b);
t_node *count_move_b(t_node *stack_b, t_node **stack_a);
//26-05-2025
int count_move(t_node *stack_b, int ref);
int count_move_a(t_node *stack_a, int ref);


// sort to b 
void sort_stack_b(t_node **stack_a, t_node **stack_b);


#endif