/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:54 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 11:43:06 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_exec_rule(char *rule, int i, t_node **a, t_node **b)
{
	if (!ft_strncmp(rule, "sa", i))
		sa_sb(a);
	else if (!ft_strncmp(rule, "sb", i))
		sa_sb(b);
	else if (!ft_strncmp(rule, "pa", i))
		pa_pb(b, a);
	else if (!ft_strncmp(rule, "pb", i))
		pa_pb(a, b);
	else if (!ft_strncmp(rule, "ra", i))
		ra_rb(a);
	else if (!ft_strncmp(rule, "rb", i))
		ra_rb(b);
	else if (!ft_strncmp(rule, "rr", i))
		rr(a, b);
	else if (!ft_strncmp(rule, "rra", i))
		rra_rrb(a);
	else if (!ft_strncmp(rule, "rrb", i))
		rra_rrb(b);
	else if (!ft_strncmp(rule, "rrr", i))
		rrr(a, b);
	else
		return (-1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (((unsigned char)*s1 || (unsigned char)*s2) && n--)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
