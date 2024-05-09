/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:17:58 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/09 14:53:29 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %s Prints a string (as defined by the common C convention).

#include "ft_printf.h"

int	ft_printfs(char *s)
{
	int	i;

	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
