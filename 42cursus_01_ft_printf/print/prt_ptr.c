/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeekim < daeekim@student.42gyeongsan      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:28:55 by daeekim           #+#    #+#             */
/*   Updated: 2024/04/17 21:46:07 by daeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	p_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	put_ptr(unsigned long long addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		put_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

int	prt_ptr(void *addr)
{
	if (addr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_ptr((unsigned long long)addr);
	return (p_digits((unsigned long long)addr) + 2);
}
