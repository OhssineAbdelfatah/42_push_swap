/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:40 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 15:15:22 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void				sa_sb(t_node **stack);
void				pa_pb(t_node **base, t_node **target);
void				ra_rb(t_node **stack);
void				rra_rrb(t_node **stack);

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
//                             CHECKER                                //
//////////////////////////////////////////////////////////////////////*/

t_node				*creat_node(int num);
void				free_args(char **arg);
void				free_stack(t_node **node);
int					is_sorted(t_node *stack);

/*//////////////////////////////////////////////////////////////////////
//                             UTILS                                  //
//////////////////////////////////////////////////////////////////////*/

void				put_message(char *str, int fd);
int					lstsize(t_node *lst);
t_node				*creat_node(int num);
int					add_to_stack(t_node *node, t_node **head);
int					execute_rule(t_node **stack_a, t_node **stack_b);
int					check_exec_rule(char *rule, int i, t_node **a, t_node **b);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					execute_rule(t_node **stack_a, t_node **stack_b);

#endif
