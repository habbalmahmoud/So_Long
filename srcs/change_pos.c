/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:38:39 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 03:41:30 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_pos_s(t_data *game_data)
{
	if (game_data->map->map[game_data->map->player[0] + 1]
		[game_data->map->player[1]] == 'C')
		game_data->map->coll_num -= 1;
	game_data->map->map[game_data->map->player[0] + 1]
	[game_data->map->player[1]] = 'P';
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1]] = '0';
	game_data->map->player[0] += 1;
}

void	change_pos_d(t_data *game_data)
{
	if (game_data->map->map[game_data->map->player[0]]
		[game_data->map->player[1] + 1] == 'C')
		game_data->map->coll_num -= 1;
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1] + 1] = 'P';
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1]] = '0';
	game_data->map->player[1] += 1;
	game_data->counter++;
}

void	change_pos_a(t_data *game_data)
{
	if (game_data->map->map[game_data->map->player[0]]
		[game_data->map->player[1] - 1] == 'C')
		game_data->map->coll_num -= 1;
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1] - 1] = 'P';
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1]] = '0';
	game_data->map->player[1] -= 1;
}
