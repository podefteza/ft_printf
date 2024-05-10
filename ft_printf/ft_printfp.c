/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:32:13 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/09 14:56:01 by carlos-j         ###   ########.fr       */
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
