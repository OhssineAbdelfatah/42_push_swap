/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:10 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/16 12:05:45 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(char type, va_list arg, int *i, int *len)
{
	if (type == 'c')
		printchar(va_arg(arg, int), len);
	else if (type == 'd' || type == 'i')
		printnbr(va_arg(arg, int), len, type);
	else if (type == 's')
		printstr(va_arg(arg, char *), len);
	else if (type == '%')
		printchar('%', len);
	else if (type == 'u')
		printnbr(va_arg(arg, unsigned int), len, type);
	else if (type == 'p')
		printhexa((unsigned long)va_arg(arg, void *), len, type);
	else if (type == 'x' || type == 'X' )
		printhexa(va_arg(arg, unsigned int), len, type);
	else if (type == '\0' )
		return ;
	else
		printchar(type, len);
	(*i)++;
	return ;
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0 ;
	len = 0 ;
	va_start(arg, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			check_format(string[i +1], arg, &i, &len);
		else
			printchar((char)string[i], &len);
		if (*(string + i))
			i++;
	}
	va_end (arg);
	return (len);
}
