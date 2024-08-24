/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:48:31 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/12 02:51:28 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*get_file(int fd, char *buffer, char *left)
{
	ssize_t		bytes_read;
	char		*str;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left);
			return (0);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left)
			left = ft_strdup_("");
		str = left;
		left = ft_strjoin_(str, buffer);
		free(str);
		str = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*get_after_new_line(char *line)
{
	char	*next;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (0);
	next = ft_substr_(line, i + 1, ft_strlen_(line) - i);
	if (*next == 0)
	{
		free(next);
		next = NULL;
	}
	line[i + 1] = '\0';
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		free(left);
		left = NULL;
		buffer = NULL;
	}
	line = get_file(fd, buffer, left);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left = get_after_new_line(line);
	return (line);
}

// #include <stdio.h>
// int main(void)
// {
//     int fd;
//     char *line;
//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     while ((line = get_next_line(-42)) != NULL)
//     {
//         printf("%s", line);
//         free(line); 
//     }
//     close(fd);
//     return 0;
// }