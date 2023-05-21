/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:07:54 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/05/11 12:47:14 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_p_pixel / 8));
	*(unsigned int *)dst = color;
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.x_size, &img.y_size);
	if (img.img == NULL)
		perror("Error\nImage failed to push to window");
	img.addr = mlx_get_data_addr(img.img, &img.bits_p_pixel,
			&img.line_len, &img.endian);
	return (img);
}

int	put_player(t_image *milei, t_vars vars, int x_pos, int y_pos)
{
	char	*relative_path;
	int		x;
	int		y;
	int		fd;

	relative_path = "assets/milei.xpm";
	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nMilei file could not be opened\n"), 1);
	close(fd);
	*milei = ft_new_sprite(vars.mlx, relative_path);
	milei->y_pos = y_pos;
	milei->x_pos = x_pos;
	x = milei->x_pos;
	y = milei->y_pos;
	mlx_put_image_to_window(vars.mlx, vars.win, milei->img, x, y);
	return (0);
}

void	free_matrix(int	**matrix, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		free(matrix[i]);
	free(matrix);
}

int	check_row_len(char	*line, int len)
{
	int	line_len;

	if (ft_strchr(line, '\n'))
		line_len = (int)ft_strlen(line) - 1;
	else
		line_len = (int)ft_strlen(line);
	free(line);
	if (line_len != len)
		return (0);
	return (1);
}
