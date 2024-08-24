/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:01:30 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/20 18:41:07 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	handle_char(int c, int *i, int *counter)
{
	*counter = *counter + 1;
	ft_putchar_fd(c, 1);
	*i = *i + 2;
}

void	handle_perc(int *i, int *counter)
{
	*counter = *counter + 1;
	ft_putchar_fd('%', 1);
	*i = *i + 2;
}
