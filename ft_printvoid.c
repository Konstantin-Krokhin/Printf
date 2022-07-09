/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:26:00 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/08 23:13:27 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void put_nbr(uintptr_t num)
{
	if (num >= 16)
	{
		put_nbr(num / 16);
		put_nbr(num % 16);
	}
	else
	{
		// if (num > 9)
		// 	ft_putchar_fd((num - 10 + 'a'), 1);
		// else
		// 	ft_putchar_fd((num + '0'), 1);
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printvoid(unsigned long int ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		put_nbr(ptr);
		length += ptr_len(ptr);
	}
	return (length);
}