/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 02:57:55 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/11 23:11:09 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>

# include "../Libft/libft.h"

int		ft_printf(const char *inp, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putptr_fd(size_t ptr, int fd, int *counter);
void	handle_char(int c, int *i, int *counter);
void	handle_strng(char *str, int *i, int *counter);
void	handle_ptr(void *ptr, int *i, int *counter);
void	ft_putnbr_fd_(int n, int fd, int *counter);
void	handle_num(int num, int *i, int *counter);
void	handle_num_u(unsigned int num, int *i, int *counter);
void	handle_num_hex_sml(unsigned int num, int *i, int *counter);
void	handle_num_hex_lg(unsigned int num, int *i, int *counter);
void	handle_perc(int *i, int *counter);

#endif