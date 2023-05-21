/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:38:23 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/12 09:45:22 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_win_two(t_map *map, int **matrix)
{
	int	y;
	int	x;
	int	*p_pos;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->row_len)
		{
			if (matrix[y][x] == 4)
				matrix[y][x] = 1;
		}
	}
	p_pos = where_is_p(matrix, map);
	if (!p_pos)
		return (perror("Error\nMalloc not allocated correctly"), 0);
	explore_board(p_pos, matrix, map);
	free(p_pos);
	if (!check_win(map, matrix))
		return (0);
	return (1);
}
