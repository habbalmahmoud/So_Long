/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:58:48 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/23 16:42:45 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_check(int	*collect, int *exit, int *player_position, char **map)
{
	int	new_pos[2];

	if (map[player_position[0]][player_position[1]] == '1')
		return ;
	else
	{
		if (map[player_position[0]][player_position[1]] == 'E')
			*exit = *exit + 1;
		else if (map[player_position[0]][player_position[1]] == 'C')
			*collect = *collect + 1;
		map[player_position[0]][player_position[1]] = '1';
		new_pos[0] = player_position[0] + 1;
		new_pos[1] = player_position[1];
		start_check(collect, exit, new_pos, map);
		new_pos[0] = player_position[0] - 1;
		new_pos[1] = player_position[1];
		start_check(collect, exit, new_pos, map);
		new_pos[0] = player_position[0];
		new_pos[1] = player_position[1] + 1;
		start_check(collect, exit, new_pos, map);
		new_pos[0] = player_position[0];
		new_pos[1] = player_position[1] - 1;
		start_check(collect, exit, new_pos, map);
	}
}

void	check_game_access(char **map, int collectible, int *player_position,
			char **og_map)
{
	int	collect;
	int	m_exit;

	collect = 0;
	m_exit = 0;
	start_check(&collect, &m_exit, player_position, map);
	if (m_exit != 1 || collect != collectible)
	{
		free_map(map);
		free_map(og_map);
		ft_printf("Map Error\n");
		exit(0);
	}
}
