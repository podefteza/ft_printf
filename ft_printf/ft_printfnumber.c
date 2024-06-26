/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:34:54 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/14 11:24:31 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.

#include "ft_printf.h"

void	negative(int *number, int *count)
{
	if (*number < 0)
	{
		write(1, "-", 1);
		*number = -*number;
		(*count)++;
	}
}

int	ft_printfnumber(int number)
{
	int	count;
	int	digits[12];
	int	i;

	count = 0;
	if (number == -2147483648)
		return (ft_printfs("-2147483648"));
	negative(&number, &count);
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
		ft_printfc(digits[i--] + '0');
	return (count);
}

/*
> We have conditions for both the MIN_VALUE of int and value 0;

> If the number is negative, we write the character - and convert
the number to positive;

> We than use the itoa method;
	> Storing each of the characters in digits;
		> Using the % 10 and / 10;

> We write the number using the function to print char the values
of digits backwards by adding '+0' to it;
*/
