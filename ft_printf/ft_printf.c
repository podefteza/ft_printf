/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/09 17:25:48 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_format(va_list args, const char format)
{
    if (format == 'c')
        return (ft_printfc(va_arg(args, int)));
    if (format == 's')
        return (ft_printfs(va_arg(args, char *)));
    if (format == 'p')
        return (ft_printfp(va_arg(args, void *)));
    if (format == 'd')
        return (ft_printfd(va_arg(args, long long)));
    return (0);
}


int	ft_is_conversion_specifier(char c)
{
	char	*conversion;

	conversion = "cspdiuxX%";
	while (*conversion)
	{
		if (c == *conversion)
			return (1);
		conversion++;
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    size_t i;
    int length;

    i = 0;
    length = 0;
    if (!str)
        return (-1);
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            while (str[i] && !ft_is_conversion_specifier(str[i]))
            {
                ft_printfc(str[i]);
                i++; // advance the pointer after printing
            }
            if (str[i])
            {
                length += ft_format(args, str[i]);
                i++; // advance the pointer after processing the specifier
            }
        }
        else
        {
            ft_printfc(str[i]);
            i++;
            length++;
        }
    }
    va_end(args);
    return (length);
}

// cspdiuxX%
/*
int	main(void)
{
	char	c = 'x';
	char	p = 'y';
	char	s[] = "42 Porto";
	int	n = 012;

	ft_printf("%c %s %s %p %d %i Text to print...\n", c, s, "Portugal", &p, n, n);
	printf("%c %s %s %p %d %i Text to print...\n", c, s, "Portugal", &p, n, n);
}*/

