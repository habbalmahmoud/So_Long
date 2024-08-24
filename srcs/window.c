/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:49:12 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 12:20:33 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	del_app(t_data *game_data)
{
	free_images(game_data);
	mlx_destroy_window(game_data->mlx_ptr, game_data->win_ptr);
	mlx_destroy_display(game_data->mlx_ptr);
	free(game_data->mlx_ptr);
	free_map(game_data->map->map);
	exit(0);
	return (0);
}

void	render_edges(t_data *game_data)
{
	int		i;

	i = -1;
	while ((size_t)++i < ft_strlen(game_data->map->map[0]) - 1)
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->win_ptr, game_data->tree, i * 64, 0 * 64);
	i = -1;
	while ((size_t)++i < ft_strlen(game_data->map->map[0]) - 1)
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->win_ptr, game_data->tree, i * 64,
			(two_dim_array_len(game_data->map->map) - 1) * 64);
	i = 0;
	while (++i < two_dim_array_len(game_data->map->map) - 1)
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->win_ptr, game_data->tree, 0 * 64, i * 64);
	i = 0;
	while (++i < two_dim_array_len(game_data->map->map) - 1)
		mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
			game_data->tree,
			(ft_strlen(game_data->map->map[0]) - 2) * 64, i * 64);
}

void	render_content(t_data *game_data)
{
	int			x;

	x = 18;
	game_data->player = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/player_.xpm", (&x), (&x));
	game_data->collect = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/key_.xpm", (&x), (&x));
	game_data->exit = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/exit_.xpm", (&x), (&x));
	game_data->ground = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/ground_.xpm", (&x), (&x));
	game_data->rock = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/orange_rock.xpm", (&x), (&x));
	game_data->tree = mlx_xpm_file_to_image(game_data->mlx_ptr,
			"textures/purple_trees.xpm", &x, &x);
}

int	key_press(int keysym, t_data *game_data)
{
	if (keysym == 65307)
		del_app(game_data);
	check_a_key(keysym, game_data);
	check_d_key(keysym, game_data);
	check_s_key(keysym, game_data);
	check_w_key(keysym, game_data);
	return (1);
}

int	start_window(t_map *map)
{
	t_data	game_data;

	game_data.map = map;
	game_data.counter = 0;
	game_data.mlx_ptr = mlx_init();
	if (!game_data.mlx_ptr)
		return (0);
	game_data.win_ptr = mlx_new_window(game_data.mlx_ptr,
			(ft_strlen(game_data.map->map[0]) - 1) * 64,
			two_dim_array_len(game_data.map->map) * 64, "Shadow");
	if (!game_data.win_ptr)
		return (free(game_data.mlx_ptr), 0);
	render_content(&game_data);
	render_edges(&game_data);
	print_content(&game_data);
	mlx_hook(game_data.win_ptr, KeyRelease, KeyReleaseMask, &key_press,
		&game_data);
	mlx_hook(game_data.win_ptr, DestroyNotify, StructureNotifyMask, &del_app,
		&game_data);
	mlx_loop(game_data.mlx_ptr);
	return (1);
}
