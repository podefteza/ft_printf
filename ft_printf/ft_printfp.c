/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:32:13 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/14 12:36:34 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format.

#include "ft_printf.h"

int	ft_printfp(void *pointer)
{
	unsigned long long	address;
	char				*hex;
	char				buffer[16];
	int					i;

	if (pointer == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)pointer;
	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		buffer[15 - i] = hex[address % 16];
		address = address / 16;
		i++;
	}
	write(1, "0x", 2);
	i = 0;
	while (buffer[i] == '0' && i < 16)
		i++;
	write(1, buffer + i, 16 - i);
	return (2 + (16 - i));
}
/*
> We start by copying the value of the pointer and giving the array of characters
to convert to hex (In general, memory addresses are stored as unsigned integer
values);

> We start by copying the address to the end of the buffer:
	> 0xb73eb000 in reallity is 3074338816
	> buffer[15] = hex[3074338816 % 16]
	> buffer [15] = hex[0]
	> buffer [14] = hex[192146176 % 16]
	> buffer [14] = hex[00]
	> buffer [13] = hex[12009136 % 16]
	> buffer [13] = hex[000]
	> buffer [12] = hex[750571 % 16]
	> buffer [12] = hex[b000]
	> buffer [11] = hex[46910 % 16]
	> buffer [11] = hex[eb000]
	> buffer [10] = hex[2931 % 16]
	> buffer [10] = hex[3eb000]
	> buffer [9] = hex[183 % 16]
	> buffer [9] = hex[73eb000]
	> buffer [8] = hex[11 % 16]
	> buffer [8] = hex[b73eb000]
	> buffer [7] = hex[0 % 16]
	> buffer [7] = hex[0b73eb000]
	...
	> keeps filling with zeros until buffer[00000000b73eb000];

> When i reaches 16, resets it to 0 and starts writing in hex, first writes 0x;

> Then starts writing the values in the buffer, ignoring the first zeros it
encounters;

> In this example, it will only start writing at b73eb000, ignoring 8 zeros;
*/
