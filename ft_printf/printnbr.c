/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:46 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/10 17:41:47 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnbr(long n, int *len, char type)
{
	if (n == -2147483648 && type == 'd')
	{
		printstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		printchar('-', len);
		n *= -1;
	}
	if (n > 9)
	{
		printnbr(n / 10, len, type);
		printnbr(n % 10, len, type);
	}
	else
		printchar(n + 48, len);
}
