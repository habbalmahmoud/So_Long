/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:33:32 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 09:56:22 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_p_and_c(t_data *game_data, int i, int j)
{
	if (game_data->map->map[i][j] == 'P')
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->win_ptr, game_data->player, j * 64, i * 64);
	else if (game_data->map->map[i][j] == 'C')
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->win_ptr, game_data->collect, j * 64, i * 64);
}

void	print_content(t_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	while (++i < two_dim_array_len(game_data->map->map) - 1)
	{
		j = 0;
		while ((size_t)++j < ft_strlen(game_data->map->map[0]) - 2)
		{
			check_p_and_c(game_data, i, j);
			if (game_data->map->map[i][j] == '0')
				mlx_put_image_to_window(game_data->mlx_ptr,
					game_data->win_ptr, game_data->ground, j * 64, i * 64);
			else if (game_data->map->map[i][j] == '1')
				mlx_put_image_to_window(game_data->mlx_ptr,
					game_data->win_ptr, game_data->rock, j * 64, i * 64);
			else if (game_data->map->map[i][j] == 'E')
				mlx_put_image_to_window(game_data->mlx_ptr,
					game_data->win_ptr, game_data->exit, j * 64, i * 64);
		}
	}
}

int	check_a_key(int keysym, t_data *game_data)
{
	if (keysym == 97)
	{
		if (game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] - 1] == '0'
			|| game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] - 1] == 'C')
		{
			change_pos_a(game_data);
			game_data->counter++;
			ft_printf("Moves: %d\n", game_data->counter);
		}
		else if (game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] - 1] == 'E')
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

int	check_s_key(int keysym, t_data *game_data)
{
	if (keysym == 115)
	{
		if (game_data->map->map[game_data->map->player[0] + 1]
			[game_data->map->player[1]] == '0'
			|| game_data->map->map[game_data->map->player[0] + 1]
			[game_data->map->player[1]] == 'C')
		{
			change_pos_s(game_data);
			game_data->counter++;
			ft_printf("Moves: %d\n", game_data->counter);
		}
		else if (game_data->map->map[game_data->map->player[0] + 1]
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

int	check_d_key(int keysym, t_data *game_data)
{
	if (keysym == 100)
	{
		if (game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] + 1] == '0'
			|| game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] + 1] == 'C')
		{
			change_pos_d(game_data);
			ft_printf("Moves: %d\n", game_data->counter);
		}
		else if (game_data->map->map[game_data->map->player[0]]
			[game_data->map->player[1] + 1] == 'E')
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
