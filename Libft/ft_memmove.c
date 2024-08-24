/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:19:12 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 14:49:34 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srcc;
	size_t			i;

	dst = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (dst > srcc && dst < srcc + n)
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = srcc[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
