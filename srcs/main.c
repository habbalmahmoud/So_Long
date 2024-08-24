/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:56:12 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 12:07:00 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	initialize_game_map(t_map *game_map)
{
	game_map->coll_num = 0;
	game_map->exit[0] = 0;
	game_map->exit[1] = 0;
	game_map->player[0] = 0;
	game_map->player[1] = 0;
	game_map->map = NULL;
}

void	fill_coll_pos(t_map *game_map, char **map)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < two_dim_array_len(map))
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				game_map->coll_pos[++k][0] = i;
				game_map->coll_pos[k][1] = j;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_map	game_map;

	initialize_game_map(&game_map);
	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	map = checking_the_map(argv[1]);
	validate_the_map(map, &game_map);
	game_map.map = map;
	start_window(&game_map);
	free_map(map);
}
