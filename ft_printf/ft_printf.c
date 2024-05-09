/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/09 08:17:53 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;
	char	*conversion;
	int		length;

	if (!str)
		return (-1);
	i = 0;
	j = 0;
	conversion = "cspdiuxX%";
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = 0;
			while (conversion[j])
			{
				if (str[i] == conversion[j])
				{
					ft_format(args, conversion[j]);
					length++;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	va_end(args);
	return (length);
}

// cspdiuxX%
/*
int	main(void)
{
	char c = 'x';
	char linebreak = '\n';
	char s[] = "42 Porto";
	ft_printf("%c %c %s %c %s %c Ignore this by now...", c, linebreak, s,
		linebreak, "Portugal", linebreak);
}*/
