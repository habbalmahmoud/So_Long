/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:30:36 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/15 14:17:49 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_left_border(char **map)
{
	int	i;

	i = 1;
	while (i < two_dim_array_len(map) - 1)
	{
		if (map[i][0] != '1')
		{
			free_map(map);
			ft_printf("Map Error\n");
			exit(0);
		}
		i++;
	}
}

void	check_right_border(char **map)
{
	int	i;
	int	j;

	j = 1;
	i = ft_strlen(map[0]);
	while (j < two_dim_array_len(map) - 1)
	{
		if (map[j][i - 2] != '1')
		{
			free_map(map);
			ft_printf("Map Error\n");
			exit(0);
		}
		j++;
	}
}

void	check_borders(char **map)
{
	int	i;
	int	map_len;

	map_len = two_dim_array_len(map);
	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] != '\n')
	{
		free_map(map);
		ft_printf("Error Map1\n");
		exit(0);
	}
	i = 0;
	while (map[map_len - 1][i] == '1')
		i++;
	if (map[map_len - 1][i] != '\0')
	{
		free_map(map);
		ft_printf("Error Map\n");
		exit(0);
	}
	check_left_border(map);
	check_right_border(map);
}

void	check_data(char **map)
{
	int		i;
	size_t	j;

	i = -1;
	while (++i < two_dim_array_len(map))
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
			{
				if (j == (ft_strlen(map[i]) - 1) && map[i][j] == '\n')
					continue ;
				else
				{
					free_map(map);
					ft_printf("Map Error\n");
					exit(0);
				}
			}
		}
	}
}

void	validate_the_map(char **map, t_map *game_map)
{
	check_data(map);
	check_borders(map);
	handle_map_spots(map, game_map);
	check_availability(map);
}
