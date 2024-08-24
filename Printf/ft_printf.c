/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 02:53:49 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/21 09:20:25 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

void	handle_char_c(char c, int *counter, int *i)
{
	write (1, &c, 1);
	*i = *i + 1;
	*counter = *counter + 1;
}

void	ft_format(const char *inp, va_list args, int *counter)
{
	int	i;

	i = 0;
	while (inp[i])
	{
		if (inp[i] == '%' && inp[i + 1] == 'c')
			handle_char(va_arg(args, int), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == 's')
			handle_strng(va_arg(args, char *), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == 'p')
			handle_ptr(va_arg(args, void *), &i, counter);
		else if (inp[i] == '%' && (inp[i + 1] == 'd' || inp[i + 1] == 'i'))
			handle_num(va_arg(args, int), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == 'u')
			handle_num_u(va_arg(args, unsigned int), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == 'x')
			handle_num_hex_sml(va_arg(args, unsigned int), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == 'X')
			handle_num_hex_lg(va_arg(args, unsigned int), &i, counter);
		else if (inp[i] == '%' && inp[i + 1] == '%')
			handle_perc(&i, counter);
		else
			handle_char_c(inp[i], counter, &i);
	}
}

int	ft_printf(const char *inp, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, inp);
	if (!inp)
		return (0);
	ft_format(inp, args, &counter);
	va_end(args);
	return (counter);
}
