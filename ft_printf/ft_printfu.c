/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:16 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/14 11:25:11 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %u Prints an unsigned decimal (base 10) number.

#include "ft_printf.h"

int	ft_printfu(unsigned int number)
{
	int				count;
	int				digits[20];
	int				i;

	count = 0;
	if (number == 0)
		return (ft_printfc('0'));
	i = 0;
	while (number != 0)
	{
		digits[i++] = number % 10;
		number = number / 10;
		count++;
	}
	i--;
	while (i >= 0)
	{
		ft_printfc(digits[i] + '0');
		i--;
	}
	return (count);
}
/*
> This is pretty much similar to the ft_printfnumber function, however
it doesn't need to handle negative numbers, so the array can now have 20 indexes;
*/
