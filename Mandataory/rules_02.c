/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:45:38 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/30 19:47:12 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node *stack_a, t_node *stack_b)
{
	put_message("ss\n", 1);
	if (stack_b == NULL && stack_a == NULL)
		return ;
	sa_sb(&stack_a, '0');
	sa_sb(&stack_b, '0');
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	put_message("rr\n", 1);
	if (stack_a != NULL && *stack_a != NULL)
		ra_rb(stack_a, '0');
	if (stack_b != NULL && *stack_b != NULL)
		ra_rb(stack_b, '0');
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	put_message("rrr\n", 1);
	if (stack_a != NULL && *stack_a != NULL)
		rra_rrb(stack_a, '0');
	if (stack_b != NULL && *stack_b != NULL)
		rra_rrb(stack_b, '0');
	return ;
}
