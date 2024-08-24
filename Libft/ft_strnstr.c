/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:43:01 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/11 14:42:43 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	char	*bigg;
	char	*small;

	bigg = (char *)big;
	small = (char *)little;
	i = 0;
	if (small[i] == '\0')
		return (bigg);
	while (bigg[i] && i < n)
	{
		j = 0;
		while (big[i + j] == small[j] && (i + j) < n)
		{
			if (small[j + 1] == '\0')
				return (&bigg[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
