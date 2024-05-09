/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:34:54 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/09 17:37:30 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %d Prints a decimal (base 10) number.

#include "ft_printf.h"

int	ft_printfd(int number)
{
	int	count;
	int	n;
	int	digits[12];
	int	i;

	count = 0;
	n = number;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n == 0)
	{
		ft_printfc('0');
		return (1);
	}
	i = 0;
	while (n != 0)
	{
		digits[i++] = n % 10;
		n = n / 10;
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
