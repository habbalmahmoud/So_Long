/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:54:39 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 11:06:10 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srcc;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = srcc[i];
		i++;
	}
	return (dest);
}
