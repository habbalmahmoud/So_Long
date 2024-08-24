/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:56:55 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/23 16:42:42 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include "../GNL/get_next_line.h"
# include "../mlx/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

typedef struct s_map
{
	int		coll_num;
	int		**coll_pos;
	int		exit[2];
	int		player[2];
	char	**map;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*rock;
	t_map		*map;
	int			counter;
	void		*player;
	void		*ground;
	void		*exit;
	void		*collect;
	void		*tree;
}		t_data;

char	**checking_the_map(char *str);
void	validate_the_map(char **map, t_map *game_map);
int		two_dim_array_len(char **str);
void	handle_map_spots(char **map, t_map *game_map);
void	check_availability(char **map);
void	check_game_access(char **map, int collectible, int *player_position,
			char **og_map);
void	free_map(char **map);
int		start_window(t_map *map);
void	print_content(t_data *game_data);
int		check_a_key(int keysym, t_data *game_data);
int		check_s_key(int keysym, t_data *game_data);
int		check_d_key(int keysym, t_data *game_data);
int		del_app(t_data *game_data);
int		check_w_key(int keysym, t_data *game_data);
void	free_images(t_data *game_data);
void	free_content(t_data *game_data);
void	render_edges(t_data *game_data);
void	render_content(t_data *game_data);
void	change_pos_w(t_data *game_data);
void	change_pos_s(t_data *game_data);
void	change_pos_d(t_data *game_data);
void	change_pos_a(t_data *game_data);
void	free_coll_pos(t_map *map);

#endif