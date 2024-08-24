/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:45:27 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/17 23:50:42 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			j = 1;
			while (str[i + j] != c && str[i + j])
				j++;
			if (str[i + j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
