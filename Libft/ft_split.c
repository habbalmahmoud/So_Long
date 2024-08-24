/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:21 by mhabbal           #+#    #+#             */
/*   Updated: 2024/06/13 11:39:52 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	assign_big(char *sub_big, size_t *i, size_t *j, char const *s)
{
	size_t	m;

	m = 0;
	while (*i < *j)
	{
		sub_big[m] = s[*i];
		m++;
		*i = *i + 1;
	}
	sub_big[m] = '\0';
}

void	fill_big(char **big, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return ;
		j = i;
		while (!(s[j] == c))
		{
			if (s[j] == '\0')
				break ;
			j++;
		}
		big[counter] = (char *)malloc(((j - i) + 1));
		assign_big(big[counter], &i, &j, s);
		counter++;
	}
}

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (!(s[i] == c))
		{
			if (s[i] == '\0')
				break ;
			i++;
		}
		words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	biglen;
	char	**big;

	biglen = count_words(s, c);
	big = (char **)malloc((biglen + 1) * sizeof(char *));
	if (big == NULL)
		return (NULL);
	fill_big(big, s, c);
	big[biglen] = NULL;
	return (big);
}
