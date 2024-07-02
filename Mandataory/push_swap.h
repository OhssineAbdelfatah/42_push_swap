/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:45:01 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 15:16:30 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*//////////////////////////////////////////////////////////////////////
//                             STRUCTS                                //
//////////////////////////////////////////////////////////////////////*/

typedef struct s_node
{
	int				data;
	int				ind;
	struct s_node	*next;

}					t_node;

/*//////////////////////////////////////////////////////////////////////
//                             RULES                                  //
//////////////////////////////////////////////////////////////////////*/

void				sa_sb(t_node **stack, char status);
void				pa_pb(t_node **base, t_node **target, char status);
void				ra_rb(t_node **stack, char status);
void				rra_rrb(t_node **stack, char status);

void				ss(t_node *stack_a, t_node *stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

/*//////////////////////////////////////////////////////////////////////
//                             PARSING                                //
//////////////////////////////////////////////////////////////////////*/

char				is_sign_doubled(char a, char b);
int					is_space(char c);
int					check_args(int len, char **argv);
int					is_sign(char c);
t_node				*fill_args(char **argv);
int					check_double(t_node *head);
int					num(const char *str, char **arg, t_node **head);

/*//////////////////////////////////////////////////////////////////////
//                             PUSH_ALGO                              //
//////////////////////////////////////////////////////////////////////*/

void				sort_temp(t_node **stack_a);
void				index_stack_a(t_node **stack_a, int *sorted_stk);
int					*bubble_sort(int *temp, int size);
void				sort_to_b(t_node **stack_a, t_node **stack_b, int range);
void				sort_to_a(t_node **stack_a, t_node **stack_b);

/*//////////////////////////////////////////////////////////////////////
//                             UTILS                                  //
//////////////////////////////////////////////////////////////////////*/

char				*ft_itoa(int n);
void				put_message(char *str, int fd);
int					lstsize(t_node *lst);
t_node				*creat_node(int num);

int					add_to_stack(t_node *node, t_node **head);
void				find_min_pb(t_node **stack_a, t_node **stack_b);
int					find_min(t_node *stack_a);
void				mini_sorted(t_node **stack_a, t_node **stack_b);
int					find_max(t_node *stack);

/*//////////////////////////////////////////////////////////////////////
//                             PUSH SWAP                              //
//////////////////////////////////////////////////////////////////////*/

t_node				*creat_node(int num);
void				free_args(char **arg);
void				free_stack(t_node **node);
int					is_sorted(t_node *stack);

/*//////////////////////////////////////////////////////////////////////
//                             SORT                                   //
//////////////////////////////////////////////////////////////////////*/

void				sort_3_nbr(t_node **head);
void				sort_4_nbr(t_node **stack_a, t_node **stack_b);
void				sort_5_nbr(t_node **stack_a, t_node **stack_b);

#endif
