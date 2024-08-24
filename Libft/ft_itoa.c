/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:31 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/13 09:11:45 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	get_len(size_t n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	fill_str(char *str, int *leng, int *i, long nb)
{
	long	j;

	if (nb < 0)
	{
		str[0] = '-';
		*i = *i + 1;
		nb = nb * -1;
	}
	j = *leng;
	while (j > *i)
	{
		str[j - 1] = (nb % 10) + '0';
		nb = nb / 10;
		j = j - 1;
	}
	str[*leng] = '\0';
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		leng;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		leng = get_len(nb * -1) + 1;
		str = (char *)malloc(1 + leng);
		if (str == NULL)
			return (NULL);
	}
	else
	{
		leng = get_len(nb);
		str = (char *)malloc(1 + leng);
		if (str == NULL)
			return (NULL);
	}
	fill_str(str, &leng, &i, nb);
	return (str);
}
