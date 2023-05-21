/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:24:27 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/11 12:51:07 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_for_statics(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			map->is_player += 1;
		if (line[i] == 'C')
			map->is_collectable = 1;
		if (line[i] == 'E')
			map->is_exit += 1;
		if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
			map->is_non_valid_char = 0;
	}
}

int	check_walls(char *line, size_t row, t_map *map)
{
	int	i;

	check_for_statics(line, map);
	i = 0;
	if (row == 0 || (!ft_strchr(line, '\n')))
	{
		if (row != 0)
		{
			if (ft_strlen(line) <= row + 1)
				return (0);
		}
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != '\0')
				return (0);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			return (0);
	}
	return (1);
}

int	check_extension(char *path_to_file)
{
	char	*extension;

	extension = ft_strrchr(path_to_file, '.');
	if (!extension)
		return (0);
	if (ft_strncmp(extension, ".ber", 4))
		return (0);
	return (1);
}

int	checking_walls(int fd, t_map *map)
{
	char	*line;
	size_t	i;
	int		expected_len;

	i = 0;
	line = get_next_line(fd);
	expected_len = (int)ft_strlen(line) - 1;
	if (!check_walls(line, i, map) || !check_row_len(line, expected_len))
		return (0);
	i++;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (!check_walls(line, i, map)
				|| !check_row_len(line, expected_len))
				return (0);
		}
		i++;
	}
	return (1);
}

char	*check_map(char	*path_to_file, t_map *map)
{
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nFile could not be opened\n"), NULL);
	if (!check_extension(path_to_file))
	{
		perror("Error\nExtension is not correct\n");
		return (NULL);
	}
	map->is_non_valid_char = 1;
	if (!checking_walls(fd, map))
		return (perror("Error\nWalls not placed correctly\n"), NULL);
	close(fd);
	if (!map->is_collectable || !map->is_exit || !map->is_player)
		return (perror("Error\nPlayer or exit or collectable not found\n"), NULL);
	if (map->is_non_valid_char == 0)
		return (perror("Error\nMap has invalid character\n"), NULL);
	if (map->is_exit > 1 || map->is_player > 1)
		return (perror("Error\nMore than one player or exit\n"), NULL);
	return (path_to_file);
}
