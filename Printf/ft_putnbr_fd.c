/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:10:52 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/11 23:11:43 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_fd_(int n, int fd, int *counter)
{
	if (n == -2147483648)
	{
		write (fd, "-", 1);
		write (fd, "2147483648", 10);
		*counter = *counter + 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		*counter = *counter + 1;
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd_(n / 10, fd, counter);
		ft_putnbr_fd_(n % 10, fd, counter);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		*counter = *counter + 1;
	}
}

void	ft_putnbr_fd_num(unsigned int n, int fd, int *counter)
{
	if (n >= 10)
	{
		ft_putnbr_fd_(n / 10, fd, counter);
		ft_putnbr_fd_(n % 10, fd, counter);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		*counter = *counter + 1;
	}
}

void	handle_num(int num, int *i, int *counter)
{
	ft_putnbr_fd_(num, 1, counter);
	*i = *i + 2;
}

void	handle_num_u(unsigned int num, int *i, int *counter)
{
	unsigned int	k;

	k = num;
	ft_putnbr_fd_num(k, 1, counter);
	*i = *i + 2;
}
