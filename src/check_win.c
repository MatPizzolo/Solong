/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 04:39:03 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/09 17:04:53 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_win(t_map *map, int **matrix)
{
	int	result;
	int	y;
	int	x;

	result = 1;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->row_len)
		{
			if (matrix[y][x] == 3 || matrix[y][x] == 4)
				result = 0;
			x++;
		}
		y++;
	}
	return (result);
}

int	check_collectables(t_map *map, int **matrix)
{
	int	result;
	int	y;
	int	x;

	result = 1;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->row_len)
		{
			if (matrix[y][x] == 3)
				result = 0;
			x++;
		}
		y++;
	}	
	return (result);
}
