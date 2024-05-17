/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:44:22 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/10 17:44:24 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		printstr("(null)", len);
	else
	{
		while (s[i])
		{
			printchar(s[i], len);
			i++;
		}
		return ;
	}
	return ;
}
