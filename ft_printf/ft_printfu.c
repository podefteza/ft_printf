/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:16 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/10 12:57:52 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %u Prints an unsigned decimal (base 10) number.

#include "ft_printf.h"

int	ft_printfu(unsigned int number)
{
	int				count;
	unsigned int	n;
	int				digits[20];
	int				i;

	count = 0;
	n = number;
	if (n == 0)
		return (ft_printfc('0'));
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
