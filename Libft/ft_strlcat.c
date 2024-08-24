/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:30 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 13:28:56 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	i;
	size_t	srclen;

	srclen = 0;
	i = 0;
	destlen = 0;
	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	if (size == 0 || destlen >= size)
		return (size + srclen);
	while (src[i] != '\0' && i < size - destlen - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
