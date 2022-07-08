/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:35:24 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/08 17:51:31 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdarg.h"

int ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printchar(va_arg(args, int));

	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			length += ft_formats(args, format);
		}
		else
			length += ft_putchar(format);
		format++;
	}
	va_end(args);
	return (length);
}
