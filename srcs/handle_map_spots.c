/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_spots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:45:47 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 12:07:16 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_player(char **map, t_map *game_map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (++i < two_dim_array_len(map))
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				player++;
				game_map->player[0] += i;
				game_map->player[1] += j;
			}
		}
	}
	if (player != 1)
	{
		free_map(map);
		exit(ft_printf("Map Error1\n"));
	}
}

void	check_exit(char **map, t_map *game_map)
{
	int	i;
	int	j;
	int	m_exit;

	i = -1;
	m_exit = 0;
	while (++i < two_dim_array_len(map))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				m_exit++;
				game_map->exit[0] += i;
				game_map->exit[1] += j;
			}
			j++;
		}
	}
	if (m_exit != 1)
	{
		free_map(map);
		exit(ft_printf("Map Error\n"));
	}
}

void	assign_coll_pos(int collect, t_map *game_map)
{
	int	i;

	game_map->coll_pos = malloc(collect * sizeof(int *));
	if (!game_map->coll_pos)
		return ;
	i = -1;
	while (++i < collect)
	{
		game_map->coll_pos[i] = malloc(2 * sizeof(int));
		if (!game_map->coll_pos[i])
			return ;
	}
	free_coll_pos(game_map);
}

void	check_collectible(char **map, t_map *game_map)
{
	int	i;
	int	j;
	int	collect;

	i = -1;
	collect = 0;
	while (++i < two_dim_array_len(map))
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				collect++;
				game_map->coll_num++;
			}
		}
	}
	if (collect < 1)
	{
		free_map(map);
		exit(ft_printf("Map Error\n"));
	}
	assign_coll_pos(collect, game_map);
}

void	handle_map_spots(char **map, t_map *game_map)
{
	check_player(map, game_map);
	check_exit(map, game_map);
	check_collectible(map, game_map);
}
