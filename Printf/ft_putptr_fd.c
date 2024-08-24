/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:39:06 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/21 02:47:54 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putptr_fd_lg(long ptr, int fd, int *counter)
{
	char			*base;
	unsigned int	nb;

	nb = (unsigned int)ptr;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putptr_fd_lg(nb / 16, fd, counter);
		ft_putptr_fd_lg(nb % 16, fd, counter);
	}
	else
	{
		ft_putchar_fd(base[nb], fd);
		*counter = *counter + 1;
	}
}

void	ft_putptr_fd(size_t ptr, int fd, int *counter)
{
	char			*base;
	unsigned long	nb;

	nb = ptr;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putptr_fd(nb / 16, fd, counter);
		ft_putptr_fd(nb % 16, fd, counter);
	}
	else
	{
		ft_putchar_fd(base[nb], fd);
		*counter = *counter + 1;
	}
}

void	handle_ptr(void *ptr, int *i, int *counter)
{
	if (!ptr)
	{
		write (1, "(nil)", 5);
		*counter = *counter + 5;
	}
	else
	{
		write (1, "0x", 2);
		*counter = *counter + 2;
		ft_putptr_fd((long)ptr, 1, counter);
	}
	*i = *i + 2;
}

void	handle_num_hex_sml(unsigned int num, int *i, int *counter)
{
	ft_putptr_fd(num, 1, counter);
	*i = *i + 2;
}

void	handle_num_hex_lg(unsigned int num, int *i, int *counter)
{
	ft_putptr_fd_lg(num, 1, counter);
	*i = *i + 2;
}
