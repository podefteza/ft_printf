/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:30 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/14 12:35:03 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.

#include "ft_printf.h"

int	convert(int digit)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[digit]);
}

int	ft_printfx(const char *format, unsigned int n)
{
	int		count;
	int		digits[8];
	int		i;
	char	c;

	count = 0;
	if (n == 0)
		return (ft_printfc('0'));
	i = 0;
	while (n != 0)
	{
		digits[i++] = n % 16;
		n = n / 16;
		count++;
	}
	i--;
	while (i >= 0)
	{
		c = convert(digits[i]);
		if (*format == 'X' && c >= 'a' && c <= 'f')
			c -= 32;
		ft_printfc(c);
		i--;
	}
	return (count);
}
/*
> Uses the same logic of ft_printfp, but only for a value of unsigned int;
	> Keeps doing %16 and / 16 until the number is 0;

> It then checks if it's supposed to write in uppercase or not;

> Writes each character backwards;
*/
