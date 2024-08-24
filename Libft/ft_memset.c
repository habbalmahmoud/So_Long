/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:26:52 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 11:32:19 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = cc;
		i++;
	}
	return (str);
}
