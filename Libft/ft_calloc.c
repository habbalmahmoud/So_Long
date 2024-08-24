/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 08:59:50 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 15:34:12 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptrr;

	ptrr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptrr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	if ((nb != 0 && size != 0) && (nb * size) / size != nb)
		return (NULL);
	ptr = (void *)malloc(nb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
