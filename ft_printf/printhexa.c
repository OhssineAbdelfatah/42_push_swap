/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:23 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/12 18:22:25 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printhexa(unsigned long n, int *len, char type)
{
	char	*base;
	char	hex[20];
	int		indice;

	base = "0123456789abcdef";
	indice = 0;
	if (type == 'p')
		printstr("0x", len);
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		printchar('0', len);
		return ;
	}
	while (n > 0)
	{
		hex[indice] = base[n % 16];
		n = n / 16;
		indice++;
	}
	while (--indice >= 0)
		printchar(hex[indice], len);
}
