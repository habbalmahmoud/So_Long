/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:14:48 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/12 12:20:46 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>

void	check_line_len(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = -1;
	while (++i < two_dim_array_len(map))
	{
		if (i == two_dim_array_len(map) - 1)
		{
			if ((len - 1) != ft_strlen(map[i]))
			{
				free_map(map);
				exit(ft_printf("Map Error\n"));
			}
		}
		else if (len != ft_strlen(map[i]))
		{
			free_map(map);
			exit(ft_printf("Map Error\n"));
		}
	}
}

void	fill_map(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (map[0] == NULL)
	{
		free(map);
		exit(ft_printf("Error\n"));
	}
	check_line_len(map);
	free(line);
}

int	count_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

char	**checking_the_map(char *str)
{
	int		str_len;
	char	*substr;
	int		fd;
	int		fd_cpy;
	char	**map;

	str_len = ft_strlen(str);
	substr = ft_substr(str, str_len - 4, 4);
	if (ft_strncmp(substr, ".ber", 4) != 0)
	{
		free(substr);
		exit(ft_printf("Error\n"));
	}
	free(substr);
	fd = open(str, O_RDONLY);
	fd_cpy = open(str, O_RDONLY);
	if (fd < 0 || fd_cpy < 0)
		exit (ft_printf("Error reading the file!\n"));
	map = malloc((count_lines(fd_cpy) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fill_map(fd, map);
	return (map);
}
