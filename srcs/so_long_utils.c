/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:57:22 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/19 12:07:19 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	two_dim_array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_coll_pos(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->coll_num)
	{
		free(map->coll_pos[i]);
		i++;
	}
	free(map->coll_pos);
}
