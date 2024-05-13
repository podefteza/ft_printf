/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:07:54 by carlos-j          #+#    #+#             */
/*   Updated: 2024/05/12 11:24:20 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_format(va_list args, const char format);
int	ft_printf(const char *str, ...);
int	ft_printfc(int c);
int	ft_printfs(char *s);
int	ft_printfp(void *pointer);
int	ft_printfnumber(int number);
int	ft_printfu(unsigned int number);
int	ft_printfx(const char *format, unsigned int n);

#endif
