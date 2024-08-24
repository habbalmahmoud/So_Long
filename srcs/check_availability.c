/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_availability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:27:20 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/23 16:42:44 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(char **map, int *player_position)
{
	int	i;
	int	j;

	i = 0;
	while (i < two_dim_array_len(map))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_position[0] = i;
				player_position[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_num_of_collectible(char **map)
{
	int	number;
	int	i;
	int	j;

	i = 0;
	number = 0;
	while (i < two_dim_array_len(map))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				number++;
			j++;
		}
		i++;
	}
	return (number);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc((two_dim_array_len(map) + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < two_dim_array_len(map))
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	check_availability(char **map)
{
	int		player_position[2];
	int		collectible;
	char	**map_cpy;

	get_player_position(map, player_position);
	collectible = get_num_of_collectible(map);
	map_cpy = copy_map(map);
	check_game_access(map_cpy, collectible, player_position, map);
	free_map(map_cpy);
}
