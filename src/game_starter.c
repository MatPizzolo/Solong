/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:21:14 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/10 18:33:25 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_vars static	g_vaars;

int	exit_in_matrix(t_vars *vars, int i, int row)
{
	int	z;

	z = 0;
	z += put_street(*vars, (i * 50), (row * 50));
	z += put_exit_map(vars, (i * 50), (row * 50));
	return (z);
}

int	map_to_window(int *mtx, int row, t_image *milei, t_map *map)
{
	int	i;
	int	z;

	i = -1;
	z = 0;
	while (++i < map->row_len && z == 0)
	{
		if (mtx[i] == 1 && z == 0)
			z += put_wall(&g_vaars, (i * 50), (row * 50));
		else if (mtx[i] == 8 && z == 0)
			z += put_street(g_vaars, (i * 50), (row * 50));
		else if (mtx[i] == 2 && z == 0)
		{
			z += put_street(g_vaars, (i * 50), (row * 50));
			z += put_player(milei, g_vaars, (i * 50), (row * 50));
		}
		else if (mtx[i] == 3 && z == 0)
		{
			z += put_street(g_vaars, (i * 50), (row * 50));
			z += put_coleccionable(&g_vaars, (i * 50), (row * 50));
		}
		else if (mtx[i] == 4 && z == 0)
			z += exit_in_matrix(&g_vaars, i, row);
	}
	return (z);
}

void	map_to_matrix(char *line, int row, int ***matrix)
{
	int	row_len;

	row_len = ft_strlen(line);
	if (line[row_len - 1] == '\n')
		row_len--;
	*matrix = (int **)ft_realloc(*matrix, row * sizeof(int *),
			(row + 1) * sizeof(int *));
	if (!*matrix)
		return ;
	(*matrix)[row] = (int *)malloc(row_len * sizeof(int));
	if (!(*matrix)[row])
		return ;
	ft_memset((*matrix)[row], 0, row_len);
	fill_matrix_row(line, (*matrix)[row], row_len);
}

void	start_matrix(char *path_to_file, int ***matrix, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path_to_file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	map_to_matrix(line, i, matrix);
	map->row_len = ft_strlen(line) - 1;
	free(line);
	while (line)
	{
		i++;
		line = get_next_line(fd);
		if (line)
		{		
			map_to_matrix(line, i, matrix);
			free(line);
		}
	}
	map->rows = i;
	close(fd);
}

int	**start_map(t_vars *vars, t_image *milei, char *path_to_file, t_map *map)
{
	int		**matrix;
	int		i;
	int		size_x;
	char	*title;
	int		z;

	matrix = NULL;
	start_map_vars(&title, &i, &z);
	start_matrix(path_to_file, &matrix, map);
	size_x = (map->row_len * 50);
	vars->win = mlx_new_window(vars->mlx, size_x, (map->rows * 50), title);
	g_vaars = *vars;
	while (++i < map->rows)
		z += map_to_window(matrix[i], i, milei, map);
	if (z > 0)
	{
		perror("Error\nXPM could not be put to image");
		close_window(vars, matrix, map);
	}
	if (!check_last_line(path_to_file, map))
	{
		perror("Error\nIncorrect map last line");
		close_window(vars, matrix, map);
	}
	return (matrix);
}
