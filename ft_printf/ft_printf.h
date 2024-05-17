/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:25 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/16 11:29:54 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
void	printstr(char *s, int *len);
void	printchar(char c, int *len);
void	printnbr(long n, int *len, char type);
void	printhexa(unsigned long n, int *len, char type);

#endif
