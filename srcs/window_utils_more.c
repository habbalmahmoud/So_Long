/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:48:55 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 12:07:10 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_w_key(int keysym, t_data *game_data)
{
	if (keysym == 119)
	{
		if (game_data->map->map[game_data->map->player[0] - 1]
			[game_data->map->player[1]] == '0'
			|| game_data->map->map[game_data->map->player[0] - 1]
			[game_data->map->player[1]] == 'C')
		{
			change_pos_w(game_data);
			game_data->counter++;
			ft_printf("Moves: %d\n", game_data->counter);
		}
		else if (game_data->map->map[game_data->map->player[0] - 1]
			[game_data->map->player[1]] == 'E')
		{
			if (game_data->map->coll_num == 0)
			{
				game_data->counter++;
				ft_printf("Moves: %d\n", game_data->counter);
				del_app(game_data);
			}
		}
	}
	render_edges(game_data);
	print_content(game_data);
	return (1);
}

void	free_images(t_data *game_data)
{
	mlx_destroy_image(game_data->mlx_ptr, game_data->rock);
	mlx_destroy_image(game_data->mlx_ptr, game_data->player);
	mlx_destroy_image(game_data->mlx_ptr, game_data->exit);
	mlx_destroy_image(game_data->mlx_ptr, game_data->ground);
	mlx_destroy_image(game_data->mlx_ptr, game_data->collect);
	mlx_destroy_image(game_data->mlx_ptr, game_data->tree);
}

void	change_pos_w(t_data *game_data)
{
	if (game_data->map->map[game_data->map->player[0] - 1]
		[game_data->map->player[1]] == 'C')
		game_data->map->coll_num -= 1;
	game_data->map->map[game_data->map->player[0] - 1]
	[game_data->map->player[1]] = 'P';
	game_data->map->map[game_data->map->player[0]]
	[game_data->map->player[1]] = '0';
	game_data->map->player[0] -= 1;
}
