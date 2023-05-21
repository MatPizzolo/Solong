/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:24:44 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/12 09:38:59 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*where_is_p(int **matrix, t_map *map)
{
	int	*p_pos;
	int	y;
	int	x;

	p_pos = (int *)malloc(2 * sizeof(int));
	if (!p_pos)
		return (0);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->row_len)
		{
			if (matrix[y][x] == 2)
			{
				p_pos[0] = y;
				p_pos[1] = x;
				return (p_pos);
			}
			x++;
		}
		y++;
	}
	return (p_pos);
}

int	p_if_possible(int y, int x, int **t_matrix, t_map *map)
{
	int	possible;

	if (y < 0 || y >= map->rows || x < 0 || x >= map->row_len)
		return (0);
	possible = 1;
	if (t_matrix[y][x] == 8 || t_matrix[y][x] == 4 || t_matrix[y][x] == 3)
		t_matrix[y][x] = 2;
	else
		possible = 0;
	return (possible);
}

void	explore_board(int *p_pos, int **t_matrix, t_map *map)
{
	if (p_if_possible(p_pos[0] - 1, p_pos[1], t_matrix, map))
	{
		p_pos[0] -= 1;
		explore_board(p_pos, t_matrix, map);
		p_pos[0] += 1;
	}
	if (p_if_possible(p_pos[0] + 1, p_pos[1], t_matrix, map))
	{
		p_pos[0] += 1;
		explore_board(p_pos, t_matrix, map);
		p_pos[0] -= 1;
	}
	if (p_if_possible(p_pos[0], p_pos[1] - 1, t_matrix, map))
	{
		p_pos[1] -= 1;
		explore_board(p_pos, t_matrix, map);
		p_pos[1] += 1;
	}
	if (p_if_possible(p_pos[0], p_pos[1] + 1, t_matrix, map))
	{
		p_pos[1] += 1;
		explore_board(p_pos, t_matrix, map);
		p_pos[1] -= 1;
	}
}

int	**copy_matrix(int **matrix, t_map *map)
{
	int	**t_matrix;
	int	i;
	int	j;

	t_matrix = malloc(map->rows * sizeof(int *));
	if (!t_matrix)
		return (NULL);
	i = -1;
	while (++i < map->rows)
	{
		t_matrix[i] = malloc(map->row_len * sizeof(int));
		if (!t_matrix[i])
		{
			free_matrix(t_matrix, map);
			return (NULL);
		}
		j = -1;
		while (++j < map->row_len)
			t_matrix[i][j] = matrix[i][j];
	}
	return (t_matrix);
}

int	is_playable(int **matrix, t_map *map)
{
	int	*p_pos;
	int	**t_matrix;
	int	**s_matrix;

	t_matrix = copy_matrix(matrix, map);
	s_matrix = copy_matrix(matrix, map);
	if (!t_matrix || !s_matrix)
		return (perror("Error\nMalloc not allocated correctly"), 0);
	p_pos = where_is_p(t_matrix, map);
	if (!p_pos)
		return (perror("Error\nMalloc not allocated correctly"), 0);
	explore_board(p_pos, t_matrix, map);
	free(p_pos);
	if (!check_win(map, t_matrix) || !check_win_two(map, s_matrix))
	{
		free_matrix(t_matrix, map);
		free_matrix(s_matrix, map);
		free_matrix(matrix, map);
		return (perror("Error\nMap is not playable"), 0);
	}
	else
	{
		free_matrix(s_matrix, map);
		return (free_matrix(t_matrix, map), 1);
	}
}
