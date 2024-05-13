/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:48 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/12 14:32:17 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_printf(va_list args, const char format)
{
	if (format == 'c')
		return (ft_printfc(va_arg(args, int)));
	else if (format == 's')
		return (ft_printfs(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_printfp(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_printfnumber(va_arg(args, int)));
	else if (format == 'u')
		return (ft_printfu(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printfx(&format, va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printfc('%'));
	return (0);
}

int	is_conversion_specifier(char c)
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

int	handle_percent(va_list args, const char *str, size_t *i)
{
	int	length;

	if (str[*i] && is_conversion_specifier(str[*i]))
	{
		length = format_printf(args, str[*i]);
		(*i)++;
		return (length);
	}
	else
	{
		ft_printfc('%');
		ft_printfc(str[*i]);
		(*i)++;
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		length;

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
			if (str[i])
				length += handle_percent(args, str, &i);
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

/*
> Iterates through the each character;
> Checks if character is % or not;

*/
/*
int	main(void)
{
	char			c;
	char			p;
	char			s[] = "42 Porto";
	int				n;
	unsigned int	un;

	c = 'x';
	p = 'y';
	n = 010;
	un = 42;
	ft_printf("%c %s %s %p %d %i %u%% ", c, s, "Portugal", &p, n, n, un);
	ft_printf("Hexadecimal: %x %X | %k --> not a specifier\n", un, un, un, p);
	printf("%c %s %s %p %d %i %u%% Hexadecimal: %x %X\n", c, s, "Portugal", &p,
		n, n, un, un, un);
}

*/
