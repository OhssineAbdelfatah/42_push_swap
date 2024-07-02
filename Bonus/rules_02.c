/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:51 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 09:33:52 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_node *stack_a, t_node *stack_b)
{
	if (stack_b == NULL && stack_a == NULL)
		return ;
	sa_sb(&stack_a);
	sa_sb(&stack_b);
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		ra_rb(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		ra_rb(stack_b);
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		rra_rrb(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		rra_rrb(stack_b);
	return ;
}
